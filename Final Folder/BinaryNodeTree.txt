#include "BinaryNodeTree.h"
#include <iostream>
// Default
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
    : rootPtr(nullptr){
          // Make Empty Tree by setting childern and root to null
      };
// Primaterized
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
    : rootPtr(
          std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)){
          // Call Paramaterized constructor of BinaryNode
      };
// Paramaterized but with children
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(
    const ItemType& rootItem,
    const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
    const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, leftTreePtr,
                                                     rightTreePtr)){
          // Call Paramaterized constructor of BinaryNode but this time with
          // children
      };
// Copy constructor
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(
    const std::shared_ptr<BinaryNodeTree<ItemType>>& treePtr) {
  // Send to function that returns a copied tree
  rootPtr = copyTree(treePtr.rootPtr);
};
// Copy tree function (Protected)
template <class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(
    const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const {
  // Declare variables
  std::shared_ptr<BinaryNode<ItemType>> newPointer;

  // Copy using preorder
  if (oldTreeRootPtr != nullptr) {
    // copy the node and it's children through recursion
    newPointer = std::make_shared<BinaryNode<ItemType>>(
        oldTreeRootPtr->getitem(), nullptr, nullptr);
    // Copy the left child
    newPointer->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    // Copy all the way down to the right child
    newPointer->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
  }
  // Return Copied Pointer
  return newPointer;
};
// Destrcutor
template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
  // Call the destroy function in protected
  this->destroyTree(rootPtr);
};
// destroy Tree function (Protected)
template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
  if (subTreePtr != nullptr) {
    // recursivley destroy each node in tree by calling children
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    // decrement counter
    subTreePtr.reset();
  }
};
// Get Height Function (simply calls the get hight helper function)
template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
  int resultHeight = 0;
  resultHeight = getHeightHelper(rootPtr);
  return resultHeight;
};
// GetHeightHelper (Protected)
template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
  // If tree empty return 0
  if (subTreePtr == nullptr) return 0;
  // Otherwise use formula from slides to do 1
  // Added with the tallest tree
  else
    return (1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                         getHeightHelper(subTreePtr->getRightChildPtr())));
};
// Add function
template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
  std::shared_ptr<BinaryNode<ItemType>> newNode =
      std::make_shared<BinaryNode<ItemType>>(newData);
  rootPtr = balancedAdd(rootPtr, newNode);
  return 1;
};
// Balance Add
template <class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {
  // If tree is empty make root new pointer by returning
  if (subTreePtr == nullptr)
    return newNodePtr;
  else {
    // Obtain both children
    auto leftPtr = subTreePtr->getLeftChildPtr();
    auto rightPtr = subTreePtr->getRightChildPtr();
    // If left child has more nodes add to the right side
    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
      // Recursive call to go to next level
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      // On last level and still right has fewer nodes
      subTreePtr->setRightChildPtr(rightPtr);
    }
    // If left child has less or the tree is balanced add to left side
    // Do this also is tree is balanced because it is a common practice
    else {
      // Recursive call to go to next level
      leftPtr = balancedAdd(leftPtr, newNodePtr);
      // On last level and still left has fewer nodes
      subTreePtr->setLeftChildPtr(leftPtr);
    }
    return subTreePtr;
  }
};
// Remove Function
template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data) {
  bool Check = 0;
  this->removeValue(rootPtr, data, Check);
  return Check;
};
// Move Values UpTree function
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
BinaryNodeTree<ItemType>::moveValuesUpTree(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
 // Declarire Variables
  std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr;
  std::shared_ptr<BinaryNode<ItemType>> RightChild = subTreePtr -> getRightChildPtr();
  std::shared_ptr<BinaryNode<ItemType>> LeftChild = subTreePtr -> getLeftChildPtr() ;
 // If the node is a leaf
  if (subTreePtr->isLeaf() == 1) {
   // delete by returning null
    return nullptr;
  }
  // If the node has both children
  else if (subTreePtr->getRightChildPtr() != nullptr &&
           subTreePtr->getLeftChildPtr() != nullptr) {
    // Want delete based off biggest height
    // If right height is bigger delete off of right
    if (getHeightHelper(RightChild) > getHeightHelper(LeftChild)) {
      subTreePtr -> setItem ( RightChild -> getItem()); 
      subTreePtr -> setRightChildPtr (moveValuesUpTree(RightChild)); 
    }
    // Made Default case to delete from left because
    // Common practice is to add from left so it cancels out
    else {
      subTreePtr -> setItem ( LeftChild -> getItem()); 
      subTreePtr -> setLeftChildPtr (moveValuesUpTree(LeftChild)); 
    }
    return subTreePtr;
  }
  // Node has one child
  else {
    // Make parent either the left of right child
    if (subTreePtr->getLeftChildPtr() != nullptr) {
      nodeToConnectPtr = subTreePtr->getLeftChildPtr();

    } else {
      nodeToConnectPtr = subTreePtr->getRightChildPtr();
    }

    return nodeToConnectPtr ;
  }
};
// Remove Value Function (Protected)
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target,
    bool& isSuccessful) {
  // If empty then there is nothing to remove
  // Or traverse whole tree and still nothing
  if (subTreePtr == nullptr) {
    isSuccessful = 0;
    return nullptr;
  }
  // If the item is equal to the root then just replace
  if (subTreePtr->getItem() == target) {
    isSuccessful = 1;
    subTreePtr = moveValuesUpTree(subTreePtr);
  } else {
    // recursive call to go to next level left
    std::shared_ptr<BinaryNode<ItemType>> Replace =
        removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
    // Link the temp ptr to the root to relink the tree
    if (isSuccessful) subTreePtr->setLeftChildPtr(Replace);

    if (!isSuccessful) {
      Replace =
          removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
      subTreePtr->setRightChildPtr(Replace);
    }
  }
  // Unlike BTS it is not necessary to check if value is
  // Greater or smaller because in node tree
  // It is the limiting of the height that is of peak importance
  // Not the order of the node
  return subTreePtr;
};
// Is Empty Function
template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
  if (rootPtr == nullptr)
    return 1;
  else
    return 0;
};
// Get Number Of Nodes
template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
  int Result = 0;
  Result = getNumberOfNodesHelper(rootPtr);
  return Result;
};
// Get number of Node Helper
template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
  // Declare Variables
  int CounterTotal = 0;
  // If tree not empty perform test
  if (subTreePtr != nullptr) {
    CounterTotal++;
    // recursivley destroy each node in tree by calling children
    CounterTotal += getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
    CounterTotal += getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
  } else if (subTreePtr == nullptr) {
    return 0;
  }
  return CounterTotal;
};
// Get Root Data
template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
    throw(PrecondViolatedExcept) {
  // If tree is empty
  if (isEmpty())
    throw PrecondViolatedExcept("Tree is empty. ");
  else
    return rootPtr->getItem();
};
// Set Root Data
template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) {
  rootPtr->setItem(newData);
};
// clear function
template <class ItemType>
void BinaryNodeTree<ItemType>::clear() {
  // Destory all left and right parts
  this->destroyTree(rootPtr->getLeftChildPtr());
  this->destroyTree(rootPtr->getRightChildPtr());
  // now only the root exsists which can be null
  rootPtr = nullptr;
};
// Get Entry Function
template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const
    throw(NotFoundException) {
  // Get pointer to the node that holds the desired data
  bool Found = 0;
  auto ResultNode = findNode(rootPtr, anEntry, Found);
  // If it dosent exist
  if (!Found) throw NotFoundException("Data does not exist within tree. ");
  // If pointer found then return item
  else
    return ResultNode->getItem();
};
// Contains Function
template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {
  // Use find node to see if it exsists
  bool Found = 0;
  auto ResultNode = findNode(rootPtr, anEntry, Found);
  // If not found return 0
  if (Found == 0) return 0;
  // If something found return 1
  else
    return 1;
};
// Find Node function
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(
    std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target,
    bool& isSuccessful) const {
  // If Empty Then return null so it goes back up the tree
  if (treePtr == nullptr) return nullptr;
  // If Value Matches Return Answer and mark success
  if (treePtr->getItem() == target) {
    isSuccessful = 1;  // Stays constant because referenced
    return treePtr;
  } else {
    // If not root then check all of the right children
    std::shared_ptr<BinaryNode<ItemType>> FoundNode =
        findNode(treePtr->getRightChildPtr(), target, isSuccessful);
    // If nothing is still found then do the left side
    if (!isSuccessful) {
      FoundNode = findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
    }
    return FoundNode;
  }
};
// Preorder Traversal
template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
  // Call Helper
  this->preorder(visit, rootPtr);
};
// Preorder Protected
template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(
    void visit(ItemType&),
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr != nullptr) {
    ItemType Item_Obtained = treePtr->getItem();
    visit(Item_Obtained);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
};
// Inorder Traversal
template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
  // Call Helper
  this->inorder(visit, rootPtr);
};
// Inorder Protected
template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(
    void visit(ItemType&),
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr != nullptr) {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType Item_Obtained = treePtr->getItem();
    visit(Item_Obtained);
    inorder(visit, treePtr->getRightChildPtr());
  }
};
// Post Order Traversal
template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
  // Call Helper
  this->postorder(visit, rootPtr);
};
// PostOrder Protected
template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(
    void visit(ItemType&),
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr != nullptr) {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType Item_Obtained = treePtr->getItem();
    visit(Item_Obtained);
  }
};
// Overload Function
template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(
    const BinaryNodeTree<ItemType>& rightHandSide) {
  // Told To destory first tree after copying it
  rootPtr = copyTree(rightHandSide.rootPtr);
  rightHandSide.destroyTree(rightHandSide.rootPtr);
};
