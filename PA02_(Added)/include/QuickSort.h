#ifndef QUICK_H
#define QUICK_H

#include <iostream>
#include <stdexcept>

using namespace std;

#include "SortingParent.h"

class QuickSortType : public Sorting {
 public:
  // Paramaterized & Default
  QuickSortType(int Size = 1);
  // Destructor
  ~QuickSortType();
  // Get Private data
  const unsigned long int GetSwaps();
  const unsigned long int GetComparisons();
  // Refresh swap and comp
  void RefreshSC();
  // Result Function
  void Result();
  // Functions Needed for basic Quick Sort
  void QuickSort(int Inital_Placement, int Final_Placment);
  int partition (int Inital_Placement, int Final_Placment);
  void swap(int Left_Most, int Right_Most);
 
 private:
  unsigned long int QuickSwap;
  unsigned long int QuickComparisons;
};

#endif
