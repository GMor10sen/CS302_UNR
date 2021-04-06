#include "Merge.h"
#include <fstream>
#include <iostream>
#include "SortingParent.h"
// Default Function
MergeSortType ::MergeSortType(int Size) {
  SizeOfArray = Size;
  if (Size > 0) Array = new int[Size - 1];
  MergeSwap = 0;
  MergeComparisons = 0;
};
// Destructor
MergeSortType ::~MergeSortType() {
  SizeOfArray = 0;
  RefreshSC();
  delete Array;
};
// Get Swap
const unsigned long int MergeSortType ::GetSwaps() { return MergeSwap; };
// Get Comparisons
const unsigned long int MergeSortType ::GetComparisons() {
  return MergeComparisons;
};
// Refresh
void MergeSortType ::RefreshSC() {
  MergeSwap = 0;
  MergeComparisons = 0;
};
// Result
void MergeSortType ::Result() {
  // Results of Swaps and Compares after sort
  std::cout << "  Swaps:" << MergeSwap << "\n";
  std::cout << "  Comparisons:" << MergeComparisons << "\n";
}
// Mergesort function
void MergeSortType::MergeSort(int FirstPosition, int LastPosition) {
  if (FirstPosition < LastPosition) {
    int Midpoint = FirstPosition + (LastPosition - FirstPosition) / 2;
    this->MergeSort(FirstPosition, Midpoint);
    this->MergeSort(Midpoint + 1, LastPosition);
    this->Merge(FirstPosition, Midpoint, LastPosition);
  }
};
void MergeSortType::Merge(int FirstPosition, int Mid, int LastPosition) {
  // Set Temp
  int tempArray[SizeOfArray];
  // Declare Vairables
  int first1 = FirstPosition;
  int last1 = Mid;
  int first2 = Mid + 1;
  int last2 = LastPosition;
  // Set index to first
  int index = first1;
  // Compare and place lowest in temp until both sides scanned
  while ((first1 <= last1) && (first2 <= last2)) {
    if (Array[first1] <= Array[first2]) {
      tempArray[index] = Array[first1];
      first1++;
    } else {
      MergeSwap++;
      tempArray[index] = Array[first2];
      first2++;
    }
    index++;
    MergeComparisons++;
  }
  // Copy over first sorted half into array
  while (first1 <= last1) {
    tempArray[index] = Array[first1];
    first1++;
    index++;
  }
  // Copy second sorted half
  while (first2 <= last2) {
    tempArray[index] = Array[first2];
    first2++;
    index++;
  }
  // copy full temp into array
  for (index = FirstPosition; index <= LastPosition; index++) {
    Array[index] = tempArray[index];
  }
};
