#include "Bubble.h"
#include <fstream>
#include <iostream>
#include "SortingParent.h"

// Default and paramaterized
BubbleSortType ::BubbleSortType(int Size) {
  SizeOfArray = Size;
  if (Size > 0) Array = new int[Size - 1];
  BubbleSwap = 0;
  BubbleComparisons = 0;
};
// Destructor
BubbleSortType ::~BubbleSortType() {
  SizeOfArray = 0;
  RefreshSC();
  delete Array;
};
// Get Swap
const unsigned long int BubbleSortType ::GetSwaps() { return BubbleSwap; };
// Get Comparisons
const unsigned long int BubbleSortType ::GetComparisons() {
  return BubbleComparisons;
};
// Result
void BubbleSortType ::Result() {
  // Results of Swaps and Compares after sort
  std::cout << "  Swaps:" << BubbleSwap << "\n";
  std::cout << "  Comparisons:" << BubbleComparisons << "\n";
};
// Refresh counts
void BubbleSortType ::RefreshSC() {
  BubbleSwap = 0;
  BubbleComparisons = 0;
};
// Bubble Sort Function
void BubbleSortType ::bubblesort() {
  // Declare Vairables
  bool Sorting = 0;
  int NumberOfPasses = 1;
  // Make sure every element of list is sorted
  while (!Sorting && (NumberOfPasses < SizeOfArray)) {
    // Make Sorting equal so that it can be done if already sorted
    Sorting = 1;
    // Run for loop and swap accordingly
    for (int i = 0; i < SizeOfArray - NumberOfPasses; i++) {
      // Going to compare
      BubbleComparisons++;
      if (Array[i] > Array[i + 1]) {  // Swap, increment counter, declare false
                                      // so it runs again
        this->swap(i);
        BubbleSwap++;
        Sorting = 0;
      }
    }
    NumberOfPasses++;
  }
};
// Swap Function
void BubbleSortType ::swap(int Position) {
  // Declare Variables
  int NextPosition = Position + 1;
  int temp = 0;
  // Swap
  std::cout << "Swaped: " << Array[NextPosition] << " and " << Array[Position] << " \n";
  temp = Array[NextPosition];
  Array[NextPosition] = Array[Position];
  Array[Position] = temp;
};
