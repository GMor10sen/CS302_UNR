#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <stdexcept>

using namespace std;

#include "SortingParent.h"

class MergeSortType : public Sorting {
 public:
  // Paramaterized & Default
  MergeSortType(int Size = 1);
  // Destructor
  ~MergeSortType();
  // Get Private data
  const unsigned long int GetSwaps();
  const unsigned long int GetComparisons();
  // Refresh swap and comp
  void RefreshSC();
  // Result Function
  void Result();
  // Functions Needed for basic mergsort
  void MergeSort(int FirstPosition, int LastPosition);
  void Merge(int FirstPosition, int Mid, int LastPosition);

 private:
  unsigned long int MergeSwap;
  unsigned long int MergeComparisons;
};

#endif
