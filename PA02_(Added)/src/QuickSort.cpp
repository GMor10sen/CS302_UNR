#include <iostream> 
#include "QuickSort.h"

// Default constructor 
QuickSortType ::QuickSortType(int Size) {
  SizeOfArray = Size;
  if (Size > 0) Array = new int[Size - 1];
  QuickSwap = 0;
  QuickComparisons = 0;
};

// Destructor
QuickSortType ::~QuickSortType() {
  SizeOfArray = 0;
  RefreshSC();
  delete Array;
};

// Get Swap
const unsigned long int QuickSortType ::GetSwaps() { return QuickSwap; };
// Get Comparisons
const unsigned long int QuickSortType ::GetComparisons() {
  return QuickComparisons;
};

// Refresh
void QuickSortType ::RefreshSC() {
  QuickSwap = 0;
  QuickComparisons = 0;
};

// Result
void QuickSortType ::Result() {
  // Results of Swaps and Compares after sort
  std::cout << "  Swaps:" << QuickSwap << "\n";
  std::cout << "  Comparisons:" << QuickComparisons << "\n";
};

// Quick Sort Function 
void QuickSortType :: QuickSort(int Inital_Placement, int Final_Placement)
{
  // This won't happen, just a case to test if array is proper 
    if (Inital_Placement < Final_Placement)
    {
      // Get partition value 
       int pi = partition(Inital_Placement, Final_Placement);
      // Use Value to divide up the array to quick sort
      // For time efficency
        std::cout << "call first half ";
        std::cout << Array[Inital_Placement] << " to ";
        std::cout << Array[pi - 1] << "\n";
        QuickSort(Inital_Placement, pi - 1); 
        std::cout << "call second half ";
        std::cout << Array[pi + 1] << " to ";
        std::cout << Array[Final_Placement] << "\n";
        QuickSort(pi + 1, Final_Placement); 
    }
}

// Partition Quick Sort function 
int QuickSortType::partition(int Inital_Placement, int Final_Placement)
{

  // Make pivot last element, this can really be any element
  // But putting in last makes it so you don't have to switch
  // Around anything extra
    int pivot = Array[Final_Placement];  
    std::cout << "Set partion element as " << Array[Final_Placement];
  // Keep an index for when swapping is needed later 
    int i = (Inital_Placement - 1);  
   
 // Check in loop if value is ever less than pivot, if so swap accordingly 
    for (int current_spot = Inital_Placement; current_spot < Final_Placement; current_spot++)
    {
        if (Array[current_spot] < pivot)
        {
	  // Increment Index and swap the values 
            i++;    
              swap (i,current_spot);   
        }
    }
  // Increment to put pivot in proper place in order 
    swap ((i + 1), Final_Placement);
    return (i + 1);
};

// Swap Function
void QuickSortType ::swap(int Left_Most, int Right_Most) {
  // Declare Variables
  int temp = 0;
  QuickSwap ++; 
  // Swap
  std::cout << "\nSwaped " << Array[Right_Most] << " and " << Array[Left_Most] << " \n";
  temp = Array[Right_Most];
  Array[Right_Most] = Array[Left_Most];
  Array[Left_Most] = temp;
};

