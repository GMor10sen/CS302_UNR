#include "BinaryNode.h"
#include <iostream>
// Default constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode() {
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
};
// Paramaterized constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) {
  item = anItem;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
};
// Paramaterized constructor with children
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(
    const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
    std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
  setItem(anItem);
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
};
// set item function
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
};
// get item function
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
};
// Check if leaf
template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  // If no children then it is leaf
  if (leftChildPtr == nullptr && rightChildPtr == nullptr) return 1;
  // If children it is not a leaf
  else
    return 0;
};
// Get left child data
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr()
    const {
  return leftChildPtr;
};
// Get Right child data
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr()
    const {
  return rightChildPtr;
};
// Set Left child data
template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(
    std::shared_ptr<BinaryNode<ItemType>> leftPtr) {
  leftChildPtr = leftPtr;
};
// Set Right child data
template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(
    std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
  rightChildPtr = rightPtr;
};
