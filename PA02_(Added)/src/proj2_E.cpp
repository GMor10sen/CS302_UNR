#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std::chrono;
// Global Variables
int Ten = 10;
int Thousand = 1000;
int TenThousand = 10000;
int ThirtyThousand = 30000;
int SixtyThousand = 60000;
int NintyThousand = 90000;
int HundredThousand = 100000;
// File Including
#include "Bubble.cpp"
#include "Bubble.h"
#include "Merge.cpp"
#include "Merge.h"
#include "QuickSort.h" 
#include "QuickSort.cpp" 

// Function Declaration
void GenerateRandomNumbers(bool Worst, bool Data);
double TestOneRunBubble(BubbleSortType &B1);
double TestOneRunMerge(MergeSortType &M1);
double TestOneRunQuick(QuickSortType &Q1);
void GetAvg(int Runs, int ArraySpace, bool Worst);

int main() {
// Declare Variables
int size_choice = 0;  
int sort_choice = 0;
// Get User input an fill
std::cout << "Choose a size:\n";
std::cin >> size_choice;   
QuickSortType Q1 (size_choice);
MergeSortType M1 (size_choice);
BubbleSortType B1 (size_choice);
// Choose specific sort
std:: cout << "Which sorting?\n[1]-Bubble\n[2]-Merge\n[3]-Quick\n";
std:: cin >> sort_choice; 
switch (sort_choice)
{
  case 1:
  // Test Bubble
	std::cout << "\n";
	std::cout << "Bubble:\n";
	B1.Fill();
	B1.Output(); 
	std::cout << "\n";
	B1.bubblesort();
	B1.Output(); 
	std::cout << "\n";
	break; 
   // Test Merge
   case 2:
	std::cout << "Merge:\n";
	M1.Fill();
	M1.Output(); 
	std::cout << "\n";
	M1.MergeSort(0, size_choice-1);
	M1.Output();
	std::cout << "\n";
	break; 
    // Test Quick
    case 3:
	std::cout << "Quick:\n";
	Q1.Fill();
	Q1.Output(); 
	std::cout << "\n";
	Q1.QuickSort(0, size_choice-1);
	Q1.Output(); 
	std::cout << "\n";
	break; 
    default:
	  return 0;
  	  break;
}
return 0;
};

