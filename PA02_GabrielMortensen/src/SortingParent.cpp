#include "SortingParent.h"
#include <fstream>
#include <iostream>

void Sorting ::Fill() throw(logic_error) {
  // Declare Variables
  string Input = "";
  const int Thousand = 1000;
  const int TenThousand = 10000;
  const int ThirtyThousand = 30000;
  const int SixtyThousand = 60000;
  const int NintyThousand = 90000; 
  const int HundredThousand = 100000;
  // Switch case depending
  switch (SizeOfArray) {
    case ThirtyThousand:
      Input = "ThirtyThousand.txt";
      break;
    case SixtyThousand:
      Input = "SixtyThousand.txt";
      break;
    case NintyThousand:
      Input = "NintyThousand.txt";
      break;
    case Thousand:
      Input = "Thousand.txt";
      break;
    case TenThousand:
      Input = "TenThousand.txt";
      break;
    case HundredThousand:
      Input = "HundredThousand.txt";
      break;
    default:
      throw logic_error("Size not appropriate for project...\n");
      return;
      break;
  }
  // Send file choice to read file
  ReadFile(Input);
};
// Read File Function
void Sorting ::ReadFile(const string& Input) {
  // Declare inputfile
  ifstream inputFile(Input);
  // Read from file
  for (int placement = 0; placement < SizeOfArray; placement++) {
    inputFile >> Array[placement];
  }
  inputFile.close();
};
// Getsize function
const int Sorting ::GetSize() { return SizeOfArray; };
// Ouput Function
void Sorting ::Output() {
  for (int i = 0; i < SizeOfArray; i++) {
    std::cout << Array[i] << "\n";
  }
};
