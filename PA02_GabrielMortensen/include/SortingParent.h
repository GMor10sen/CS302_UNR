//--------------------------------------------------------------------
//
//   SortingParent.h
//
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the Sorting Clases.
//
//--------------------------------------------------------------------
#ifndef SORTINGPARENT_H
#define SORTINGPARENT_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Sorting {
 public:
  // Generic Fill Function and read function
  void Fill() throw(logic_error);
  void ReadFile(const string& Input);
  // Generic Ouput and getsize
  const int GetSize();
  void Output();
  // Generic Refresh and Results
  virtual void RefreshSC() = 0;
  virtual void Result() = 0;

 protected:
  int* Array;
  int SizeOfArray;
};

#endif
