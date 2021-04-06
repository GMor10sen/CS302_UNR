#ifndef BINARY_NODE
#define BINARY_NODE
#include <memory>
//~~~~~~~~~~~Note Made For My Comprehension~~~~~~~~~~~~~~~
// This class connects with BinaryNodeTree
// BinaryNodeTree holds the main root pointer
// While BinaryNode psrovides a right and left child
// and adds the ability for data to exist inside each node
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class ItemType>
class BinaryNode {
 public:
  // Default constructor
  BinaryNode();
  // Paramaterized constructor
  BinaryNode(const ItemType& anItem);
  // Copy constructor
  BinaryNode(const ItemType& anItem,
             std::shared_ptr<BinaryNode<ItemType>> leftPtr,
             std::shared_ptr<BinaryNode<ItemType>> rightPtr);
  // set and get item functions
  void setItem(const ItemType& anItem);
  ItemType getItem() const;
  // Check if leaf
  bool isLeaf() const;
  // Get left and Right child pointer
  std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
  std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;
  // Set Left and Right child data
  void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
  void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);

 private:
  // Needs the actual item and the left and right child
  ItemType item;
  std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
  std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;
};
#endif
