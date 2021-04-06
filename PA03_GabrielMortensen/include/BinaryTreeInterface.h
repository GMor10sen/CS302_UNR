#ifndef BINARY_TREE_INTERFACE
#define BINARY_TREE_INTERFACE

//~~~~~~~~~~For My Understanding~~~~~~~~~~~~~~~
// This class defines functions that
// derived class should implement
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <class ItemType>
class BinaryTreeInterFace {
 public:
  // is empty funciton
  virtual bool isEmpty() const = 0;
  // Get height function
  virtual int getHeight() const = 0;
  // Get number of nodes function
  virtual int getNumberOfNodes() const = 0;
  // get root data
  virtual ItemType getRootData() const = 0;
  // set root data
  virtual void setRootData(const ItemType& newData) = 0;
  // add function
  virtual bool add(const ItemType& newData) = 0;
  // Remove function
  virtual bool remove(const ItemType& target) = 0;
  // clear function
  virtual void clear() = 0;
  // GetEntry function
  virtual ItemType getEntry(const ItemType& target) const = 0;
  // contains function
  virtual bool contains(const ItemType& target) const = 0;
  // traversal sections
  virtual void preorderTraverse(void visit(ItemType&)) const = 0;
  virtual void inorderTraverse(void visit(ItemType&)) const = 0;
  virtual void postorderTraverse(void visit(ItemType&)) const = 0;
  // Destructor
  virtual ~BinaryTreeInterFace() {}
};
#endif
