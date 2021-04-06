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

// Function Declaration
void menu(int &Run, int &Size, bool &Worst, bool &Data);
void GenerateRandomTextFiles(bool Worst, bool Data);
double TestOneRunBubble(BubbleSortType &B1);
double TestOneRunMerge(MergeSortType &M1);
void GetAvg(int Runs, int ArraySpace, bool Worst);

int main() {
  // Used To Make Random Each Time
  std::srand(std::time(nullptr));
  // Declaire Vairiables
  int UserSize = 0;
  int RunOption = 0;
  bool WorstCaseRequested = 0;
  bool MoreDataRequested = 0;
  // Assign Proper Size Depending On Menu or terminate program
  menu(RunOption, UserSize, WorstCaseRequested, MoreDataRequested);
  // Generate Numbers in the file
  GenerateRandomTextFiles(WorstCaseRequested, MoreDataRequested);
  // Chooses either to run with one input or all inputs depending on user choice
  if (UserSize != 1)
    GetAvg(RunOption, UserSize, WorstCaseRequested);
  else {
    GetAvg(RunOption, Thousand, WorstCaseRequested);
    GetAvg(RunOption, TenThousand, WorstCaseRequested);
    if (MoreDataRequested) {
      GetAvg(RunOption, ThirtyThousand, WorstCaseRequested);
      GetAvg(RunOption, SixtyThousand, WorstCaseRequested);
      GetAvg(RunOption, NintyThousand, WorstCaseRequested);
    }
    GetAvg(RunOption, HundredThousand, WorstCaseRequested);
  }
  return 0;
};

// Menu Function
void menu(int &Run, int &Size, bool &Worst, bool &Data) {
  // Declare Variables
  int ChoiceCompleted = 0;
  while (!ChoiceCompleted) {
    // Display choices part 1
    std::cout << "~~~Bubble & Merge Sorting!~~~\n";
    std::cout << "##Please select an option##\n";
    std::cout << "\n [0] - One Run Avg case \n [1] - Ten Runs Avg case";
    std::cout << "\n [2] - One Run Worst case \n [3] - Ten Runs Worst case\n";
    std::cin >> Run;
    switch (Run) {
      case 0:
        ChoiceCompleted = 1;
        break;
      case 1:
        ChoiceCompleted = 1;
        break;
      case 2:
        ChoiceCompleted = 1;
        Run = 0;
        Worst = 1;
        break;
      case 3:
        ChoiceCompleted = 1;
        Run = 1;
        Worst = 1;
        break;
      default:
        ChoiceCompleted = 0;
        break;
    }
  }
  // Reset bool
  ChoiceCompleted = 0;
  while (!ChoiceCompleted) {
    // Display choices part 2
    std::cout << "How many numbers would you like to try?\n";
    std::cout << "\n [1] - 1,000 \n [2] - 10,000 \n [3] - 100,000\n [4] - All "
                 "Options Above (Project Specfied)\n [5] - All options above "
                 "and 30,000 60,000 and 90,000 (Specified in Log)\n";
    // Get User Input
    std::cin >> Size;
    // Set True just in case and set size to appropriate value... else return
    ChoiceCompleted = 1;
    switch (Size) {
      case 1:
        Size = Thousand;
        break;
      case 2:
        Size = TenThousand;
        break;
      case 3:
        Size = HundredThousand;
        break;
      case 4:
        Size = 1;
        break;
      case 5:
        Size = 1;
        Data = 1;
        break;
      default:
        ChoiceCompleted = 0;
        break;
    }
  }
};
// Generating Random Txt files
void GenerateRandomTextFiles(bool Worst, bool Data) {
  // Declare variables
  int random_int = 0;
  int WorstThousand = Thousand;
  int WorstTenThousand = TenThousand;
  int WorstHundredThousand = HundredThousand;
  int WorstThirtyThousand = ThirtyThousand;
  int WorstSixtyThousand = SixtyThousand;
  int WorstNintyThousand = NintyThousand;
  int Million = 1000000;
  // Declare and write to first output file, Avg is random, Worst is reverse
  // order
  std::ofstream ThousandFile("Thousand.txt");
  for (int i = 0; i < Thousand; i++) {
    if (Worst) {
      ThousandFile << WorstThousand - i << "\n";
    } else {
      random_int = (rand() % Million) + 1;
      ThousandFile << random_int << "\n";
    }
  }
  ThousandFile.close();
  // Declare and write to secound output file
  std::ofstream TenThousandFile("TenThousand.txt");
  for (int i = 0; i < TenThousand; i++) {
    if (Worst) {
      TenThousandFile << WorstTenThousand - i << "\n";
    } else {
      random_int = (rand() % Million) + 1;
      TenThousandFile << random_int << "\n";
    }
  }
  TenThousandFile.close();
  // Declare and write to third output file
  std::ofstream HundredThousandFile("HundredThousand.txt");
  for (int i = 0; i < HundredThousand; i++) {
    if (Worst) {
      HundredThousandFile << WorstHundredThousand - i << "\n";
    } else {
      random_int = (rand() % Million) + 1;
      HundredThousandFile << random_int << "\n";
    }
  }
  HundredThousandFile.close();
  //
  if (Data) {
    // Declare and write to extra output file
    std::ofstream SixtyT("ThirtyThousand.txt");
    for (int i = 0; i < ThirtyThousand; i++) {
      if (Worst) {
        SixtyT << WorstThirtyThousand - i << "\n";
      } else {
        random_int = (rand() % Million) + 1;
        SixtyT << random_int << "\n";
      }
    }
    SixtyT.close();
    // Declare and write to extra output file
    std::ofstream ThirtyT("SixtyThousand.txt");
    for (int i = 0; i < SixtyThousand; i++) {
      if (Worst) {
        ThirtyT << WorstSixtyThousand - i << "\n";
      } else {
        random_int = (rand() % Million) + 1;
        ThirtyT << random_int << "\n";
      }
    }
    ThirtyT.close();
    // Declare and write to extra output file
    std::ofstream NintyT("NintyThousand.txt");
    for (int i = 0; i < NintyThousand; i++) {
      if (Worst) {
        NintyT << WorstNintyThousand - i << "\n";
      } else {
        random_int = (rand() % Million) + 1;
        NintyT << random_int << "\n";
      }
    }
    NintyT.close();
  }
};
// Testing Only One run
double TestOneRunBubble(BubbleSortType &B1) {
  // Time Sort
  auto t1 = high_resolution_clock::now();
  B1.bubblesort();
  auto t2 = high_resolution_clock::now();
  // Get Time Result
  duration<double> Duration = (t2 - t1);
  // Return Result
  return Duration.count();
};
// Test One run Merge function
double TestOneRunMerge(MergeSortType &M1) {
  // Time Sort
  auto t1 = high_resolution_clock::now();
  M1.MergeSort(0, M1.GetSize() - 1);
  auto t2 = high_resolution_clock::now();
  // Get Time Result
  duration<double> Duration = (t2 - t1);
  // Return Result
  return Duration.count();
};

void GetAvg(int Runs, int ArraySpace, bool Worst) {
  // Declaire Variables
  double TimeBubbleUnsort = 0;
  unsigned long int SwapsBubbleUnsort = 0;
  unsigned long int ComparisonBubbleUnsort = 0;
  double TimeBubbleSort = 0;
  unsigned long int SwapsBubbleSort = 0;
  unsigned long int ComparisonBubbleSort = 0;
  double TimeMergeUnsort = 0;
  unsigned long int SwapsMergeUnsort = 0;
  unsigned long int ComparisonMergeUnsort = 0;
  double TimeMergeSort = 0;
  unsigned long int SwapsMergeSort = 0;
  unsigned long int ComparisonMergeSort = 0;
  int UserAmount = 0;
  if (Runs == 0) {
    UserAmount = 1;
  } else if (Runs == 1) {
    UserAmount = 10;
  }
  // Create Array Of Objects
  BubbleSortType B(ArraySpace);
  MergeSortType M(ArraySpace);
  for (int i = 0; i < UserAmount; i++) {
    B.Fill();
    TimeBubbleUnsort += TestOneRunBubble(B);
    if (Runs == 0) {
      std::cout << "\t~~~Bubble Test " << ArraySpace << " ~~~\n";
      std::cout << "Bubble Unsort Time: " << TimeBubbleUnsort << " seconds\n";
      B.Result();
    }

    SwapsBubbleUnsort += B.GetSwaps();
    ComparisonBubbleUnsort += B.GetComparisons();
    B.RefreshSC();

    TimeBubbleSort += TestOneRunBubble(B);
    if (Runs == 0) {
      std::cout << "Bubble Sort Time: " << TimeBubbleSort << " seconds\n";
      B.Result();
    }

    SwapsBubbleSort += B.GetSwaps();
    ComparisonBubbleSort += B.GetComparisons();
    B.RefreshSC();

    M.Fill();
    TimeMergeUnsort += TestOneRunMerge(M);
    if (Runs == 0) {
      std::cout << "\t~~~Merge Test " << ArraySpace << " ~~~\n";
      std::cout << "Merge Unsort Time: " << TimeMergeUnsort << " seconds\n";
      M.Result();
    }

    SwapsMergeUnsort += M.GetSwaps();
    ComparisonMergeUnsort += M.GetComparisons();
    M.RefreshSC();

    TimeMergeSort += TestOneRunMerge(M);
    if (Runs == 0) {
      std::cout << "Merge Sort Time: " << TimeMergeSort << " seconds\n";
      M.Result();
    }

    SwapsMergeSort += M.GetSwaps();
    ComparisonMergeSort += M.GetComparisons();
    M.RefreshSC();
  }
  if (Runs == 1) {
    // Get Average time Of ten runs
    double UnsortBResult = TimeBubbleUnsort / 10;
    double SortBResult = TimeBubbleSort / 10;
    double UnsortMResult = TimeMergeUnsort / 10;
    double SortMResult = TimeMergeSort / 10;
    // Get Average of swaps
    unsigned long int SwapsBUnsort = SwapsBubbleUnsort / 10;
    unsigned long int SwapsBSort = SwapsBubbleSort / 10;
    unsigned long int SwapsMUnsort = SwapsMergeUnsort / 10;
    unsigned long int SwapsMSort = SwapsMergeSort / 10;
    // Get Average of Comparisons
    unsigned long int CompareBUnsort = ComparisonBubbleUnsort / 10;
    unsigned long int CompareBSort = ComparisonBubbleSort / 10;
    unsigned long int CompareMUnsort = ComparisonMergeUnsort / 10;
    unsigned long int CompareMSort = ComparisonMergeSort / 10;

    // Display Results
    if (!Worst)
      std::cout << "~~~~~~ Average Case Scenario ~~~~~~\n";
    else
      std::cout << "~~~~~~ Worst Case Scenario ~~~~~~\n";
    std::cout << "~~~ " << ArraySpace << " Numbers Bubble Sorted~~~\n";
    std::cout << "  Time To Sort Unsorted: " << UnsortBResult << " seconds\n";
    std::cout << "  Time To Sort Sorted: " << SortBResult << " seconds\n";
    std::cout << "Swaps Unsorted Bubble: " << SwapsBUnsort << " || ";
    std::cout << " Swaps Sorted Bubble: " << SwapsBSort << "\n";
    std::cout << "Comparisons Unsorted Bubble: " << CompareBUnsort << " || ";
    std::cout << " Comparisons Sorted Bubble: " << CompareBSort << "\n\n\n";

    std::cout << "~~~ " << ArraySpace << " Numbers Merge Sorted~~~\n";
    std::cout << "  Time To Sort Unsorted: " << UnsortMResult << " seconds\n";
    std::cout << "  Time To Sort Sorted: " << SortMResult << " seconds\n";
    std::cout << "Swaps Unsorted Merge: " << SwapsMUnsort << " || ";
    std::cout << " Swaps Sorted Merge: " << SwapsMSort << "\n";
    std::cout << "Comparisons Unsorted Merge: " << CompareMUnsort << " || ";
    std::cout << " Comparisons Sorted Merge: " << CompareMSort << "\n\n\n";
  }
};
