#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterFace<ItemType> {
 private:
  // Create the root pointer
  std::shared_ptr<BinaryNode<ItemType>> rootPtr;

 public:
  // Default
  BinaryNodeTree();
  // Primaterized
  BinaryNodeTree(const ItemType& rootItem);
  // Paramaterized but with children
  BinaryNodeTree(const ItemType& rootItem,
                 const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                 const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
  // Copy
  BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& treePtr);
  // Destructor
  virtual ~BinaryNodeTree();
  // Public as defined in interface
  // is empty funciton
  bool isEmpty() const;
  // Get height function
  int getHeight() const;
  // Get number of nodes function
  int getNumberOfNodes() const;
  // get root data
  ItemType getRootData() const throw(PrecondViolatedExcept);
  // set root data
  void setRootData(const ItemType& newData);
  // add function
  bool add(const ItemType& newData);
  // Remove function
  bool remove(const ItemType& data);
  // clear function
  void clear();
  // GetEntry function
  ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
  // contains function
  bool contains(const ItemType& target) const;
  // Traversal Functions
  void preorderTraverse(void visit(ItemType&)) const;
  void inorderTraverse(void visit(ItemType&)) const;
  void postorderTraverse(void visit(ItemType&)) const;
  // Overload Operator
  BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);

 protected:
  // GetHieightHelper (Protected)
  int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
  // GetNumberOfNodes (Protected)
  int getNumberOfNodesHelper(
      std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
  // Balance Add (Protected)
  auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
  // Remove value (Protected)
  virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(
      std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target,
      bool& isSuccessful);
  // Move Up Tree (Protected)
  std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(
      std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
  // FindNode (Protected)
  virtual std::shared_ptr<BinaryNode<ItemType>> findNode(
      std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target,
      bool& isSuccessful) const;
  // Copy Tree (Protected)
  auto copyTree(
      const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
  // delete everything from the tree
  void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
  // Preorder (Protected)
  void preorder(void visit(ItemType&),
                std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  // Inorder (Protected)
  void inorder(void visit(ItemType&),
               std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  // Postorder (Protected)
  void postorder(void visit(ItemType&),
                 std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
};

#endif
