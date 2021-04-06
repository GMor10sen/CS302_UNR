#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
#include <stdexcept>

using namespace std;

#include "SortingParent.h"

class BubbleSortType : public Sorting {
 public:
  // Paramaterized & Default
  BubbleSortType(int Size = 1);
  // Destructor
  ~BubbleSortType();
  // Get Private data
  const unsigned long int GetSwaps();
  const unsigned long int GetComparisons();
  // Refresh swap and comp
  void RefreshSC();
  // Result Function
  void Result();
  // Functions Needed for basic bubblesort
  void swap(int Position);
  void bubblesort();

 private:
  unsigned long int BubbleSwap;
  unsigned long int BubbleComparisons;
};

#endif
