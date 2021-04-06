#include "SortingParent.h"
#include <fstream>
#include <iostream>

void Sorting ::Fill() throw(logic_error) {

 // Declare 
  int choice = 0; 
 // Input user choice 
  for (int placement = 0; placement < SizeOfArray; placement++) {
    std:: cout << "Input element :\n";
    std:: cin >> choice;  
    Array[placement] = choice;
  }

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
    std::cout << Array[i] << " ";
  }
};
