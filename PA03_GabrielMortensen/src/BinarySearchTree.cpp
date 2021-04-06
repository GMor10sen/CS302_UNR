#include "BinarySearchTree.h"
#include <iostream>
// Default constructor
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
    : rootPtr(nullptr){
          // Set rootPtr to null
      };
// Paramaterized Constructor
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem): rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr)) {
          // Call paramaterized of BinaryNode
      };
// Copy Constructor
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(
    const BinarySearchTree<ItemType>& tree) {
  // Call copy tree Protected Function In BinaryNodeTree
  rootPtr = copyTree(tree.rootPtr);
};
// Unsure about BinarySearchTree Destructor because virtual
template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
  // Call Destroy Tree
  this->destroyTree(rootPtr);
};

// Is empty function
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
  if (rootPtr == nullptr)
    return 1;
  else
    return 0;
};
// Get Height Function
template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  int resultHeight = 0;
  resultHeight = this->getHeightHelper(rootPtr);
  return resultHeight;
};
// Get Number Of Nodes
template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
  int Result = 0;
  Result = this->getNumberOfNodesHelper(rootPtr);
  return Result;
};
// Get Root Data function
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
    throw(PrecondViolatedExcept) {
  // If tree is empty
  if (isEmpty())
    throw PrecondViolatedExcept("Tree is empty. ");
  else
    return rootPtr->getItem();
};
// Set Root Data Function
template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) {
  rootPtr->setItem(newData);
};
// Add function
template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry) {
  // Declare New Node With newEntry Data inside
  std::shared_ptr<BinaryNode<ItemType>> newNodePtr =
      std::make_shared<BinaryNode<ItemType>>(newEntry);
  // Go to place Node function
  rootPtr = placeNode(rootPtr, newNodePtr);
  return 1;
};
// Place Node Function
template <class ItemType>
auto BinarySearchTree<ItemType>::placeNode(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNode) {
  // If there is no root then make new node the root
  if (subTreePtr == nullptr) return newNode;
  // If the root's item is larger than new node
  else if (subTreePtr->getItem() > newNode->getItem()) {
    std::shared_ptr<BinaryNode<ItemType>> TemporaryPointer =
        placeNode(subTreePtr->getLeftChildPtr(), newNode);
    subTreePtr->setLeftChildPtr(TemporaryPointer);
  }
  // If the root's item is smaller than new node
  else {
    std::shared_ptr<BinaryNode<ItemType>> TemporaryPointer =
        placeNode(subTreePtr->getRightChildPtr(), newNode);
    subTreePtr->setRightChildPtr(TemporaryPointer);
  }
  return subTreePtr;
};
// Remove Node function (Protected)
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(
    std::shared_ptr<BinaryNode<ItemType>> nodePtr) {
  // Declare Variables
  std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr;
  std::shared_ptr<BinaryNode<ItemType>> tempPtr;
  // If the node is a leaf
  if (nodePtr->isLeaf() == 1) {
    // delete by returning null
    return nullptr;
  }
  // If the node has both children
  else if (nodePtr->getRightChildPtr() != nullptr &&
           nodePtr->getLeftChildPtr() != nullptr) {
    // Declare new node value by setting to nodePtr
    ItemType newNodeValue;
    // Change value of newNodeValue in function and set temp pointer
    tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
    // Make tempPtr the new right child
    nodePtr->setItem(newNodeValue);
    // Make it connect to rest of tree
    nodePtr->setRightChildPtr(tempPtr);
    return nodePtr;
  }
  // Node has one child
  else {
    // Make parent either the left of right child
    if (nodePtr->getLeftChildPtr() != nullptr)
      nodeToConnectPtr = nodePtr->getLeftChildPtr();
    else
      nodeToConnectPtr = nodePtr->getRightChildPtr();
    return nodeToConnectPtr;
  }
};
// Remove Left Most Node
template <class ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(
    std::shared_ptr<BinaryNode<ItemType>> nodePtr, ItemType& inOrderSuccessor) {
  if (nodePtr->getLeftChildPtr() == nullptr) {
    inOrderSuccessor = nodePtr->getItem();
    return removeNode(nodePtr);
  } else {
    auto tempPtr =
        removeLeftmostNode(nodePtr->getLeftChildPtr(), inOrderSuccessor);
    nodePtr->setLeftChildPtr(tempPtr);
    return nodePtr;
  }
};
// Remove function
template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target) {
  bool Check = 0;
  this->removeValue(rootPtr, target, Check);
  return Check;
};
// Remove Value Function
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target,
    bool& isSuccessful) {
  // If empty then there is nothing to remove
  // Or traverse whole tree and still nothing
  if (subTreePtr == nullptr) {
    isSuccessful = 0;
    return nullptr;
  }
  // If the item is equal to the root then just replace
  else if (subTreePtr->getItem() == target) {
    subTreePtr = removeNode(subTreePtr);
    isSuccessful = 1;
  }
  // If the target is less than the root then search the left
  else if (subTreePtr->getItem() > target) {
    // recursive call to go to next level
    std::shared_ptr<BinaryNode<ItemType>> tempPtr =
        removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
    // Link the temp ptr to the root to relink the tree
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  // If the target is greater than the root then search right and connect
  else {
    // recursive call to go to next level
    std::shared_ptr<BinaryNode<ItemType>> tempPtr =
        removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
    // Link the temp ptr to the root to relink the tree
    subTreePtr->setRightChildPtr(tempPtr);
  }
  return subTreePtr;
};
// Find Node Function
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(
    std::shared_ptr<BinaryNode<ItemType>> treePtr,
    const ItemType& target) const {
  // If nothing there then return null
  if (treePtr == nullptr) return nullptr;
  // If target found then return the node
  else if (treePtr->getItem() == target)
    return treePtr;
  // If the target is smaller than current node check left side
  else if (treePtr->getItem() > target)
    return findNode(treePtr->getLeftChildPtr(), target);
  // target is greater then check right side
  else
    return findNode(treePtr->getRightChildPtr(), target);
};
// Clear Function
template <class ItemType>
void BinarySearchTree<ItemType>::clear() {
  // Destory all left and right parts
  this->destroyTree(rootPtr->getLeftChildPtr());
  this->destroyTree(rootPtr->getRightChildPtr());
  // now only the root exsists which can be null
  rootPtr = nullptr;
};

// Get Entry Function
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const
    throw(NotFoundException) {
 // Get pointer to the node that holds the desired data
  auto ResultNode = findNode(rootPtr, anEntry);
  if (ResultNode == nullptr)
    throw NotFoundException("Data does not exist within tree. ");
  // If pointer found then return item
  else
    return ResultNode->getItem();

  // QUESTION: Why can't I call same function in BinaryNodeTree?
  // return BinaryNodeTree<ItemType>:: getEntry (anEntry);
};
// Contains Function
template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
  // Get pointer to the node that holds the desired data
  auto ResultNode = findNode(rootPtr, anEntry);
  // If nothing is found then return 0
  if (ResultNode == nullptr) return 0;
  // If something found return 1
  else
    return 1;
};
// Preorder Traversal
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
  // Call Helper
  this->preorder(visit, rootPtr);
};
// Inorder Traversal
template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
  // Call Helper
  this->inorder(visit, rootPtr);
};
// Post Order Traversal
template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(
    void visit(ItemType&)) const {
  // Call Helper
  this->postorder(visit, rootPtr);
};
// Overload Function
template <class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(
    const BinarySearchTree<ItemType>& rightHandSide) {
  // Told To destory first tree after copying it
  rootPtr = copyTree(rightHandSide.rootPtr);
  rightHandSide.destroyTree(rightHandSide.rootPtr);
};
