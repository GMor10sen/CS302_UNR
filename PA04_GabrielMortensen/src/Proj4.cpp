#include <signal.h>
#include <stdlib.h>
#include <cstddef>
#include <ctime>
#include <iostream>

#include "LeftLeaningRedBlack.h"
#include "QzCommon.h"

// ~~~~~~~~~~~~~~~~
// Define Functions
//~~~~~~~~~~~~~~~~~~
void menu_Insert(int& User_Size, int& Unique);
void menu_main(bool& Test_Case, bool& LRresponse);
int Unique_Check(int& Unique);
void ArrayUnique(int Unq[], int User_Size);
int menu_Remove(int Arr[], int Size);
void TestCases(bool Left_Right);

// Main()
// Performes main tasks described by project pdf
int main() {
  // Declaire Vairables
  LeftLeaningRedBlack TestTree;
  LeftLeaningRedBlack UpdatedTree;
  LLTB_t Test_Node;
  int Size_Option = 0;
  int Unique_Option = 2;
  int Remove_Option_Menu = 0;
  int Remove_Option_Two = 0;
  int random_int = 0;
  int i = 0;
  bool Left_Right = 0;
  bool Test_Case = 0;

  // Check if User wan't test runs or wants to try her/his own run
  menu_main(Test_Case, Left_Right);
  if (!Test_Case) {
    TestCases(Left_Right);
  } else {
    // Used To Make Output Random Each Time
    std::srand(std::time(nullptr));

    // Insertion Menu & Actions
    menu_Insert(Size_Option, Unique_Option);
    std::cout << "\n";
    // Make Array to keep track of data
    // And make an array to hold uniqe variables
    int DataInputted[Size_Option];
    int User_Choose[Size_Option];
    if (!Unique_Option) ArrayUnique(User_Choose, Size_Option);

    // Notfiy User about Method Two
    std::cout << "\n~~~Step By Step Process (Method One)~~~\n";
    std::cout << "Check Description docx for details.\n\n\n";
    // Create Loop Where Tree is filled
    // Insert Function only replaces the duplicates,
    // Meaning the program still has to check if unique
    // because we still want x amount of values
    // Made range whatever the user inputted squared
    // Becuase if fixed range then user may input over range
    // Ex) range 100 and user inputs size 101...

    while (i < Size_Option) {
      if (Unique_Option)
        random_int = (rand() % (Size_Option * Size_Option)) + 1;
      else
        random_int = User_Choose[i];
      if (i == 0 || TestTree.LookUp(random_int) == NULL) {
        DataInputted[i] = random_int;
        VoidRef_t ref;
        ref.Key = random_int;
        TestTree.Insert(ref, Left_Right);
        TestTree.GetNodeInfo(ref.Key);
        i++;
      }
    }

    // Check each inserted after tree is complete
    std::cout << "\n~~~Step By Step Process (Method Two)~~~\n";
    std::cout << "Check Description docx for details.\n\n\n";
    for (int j = 0; j < Size_Option; j++) {
      TestTree.GetNodeInfo(DataInputted[j]);
    }
    std::cout << "\n";
    // Output the order of the data inserted
    std::cout << "~~~Order Of Inserted Data~~~\n";
    for (int j = 0; j < Size_Option; j++) {
      std::cout << DataInputted[j] << " ";
    }

    // Output the traversed tree (inorder)
    std::cout << "\n\n";
    std::cout << "~~~Traverse~~~\n";
    TestTree.Traverse();
    std::cout << "\n";

    // Remove Menu & Actions
    Remove_Option_Two = menu_Remove(DataInputted, Size_Option);
    std::cout << "\n";
    // If value desired not abalible notify user and end program
    if (TestTree.LookUp(Remove_Option_Two) != NULL) {
      // Remove and double check
      std::cout << "Deleted: " << Remove_Option_Two << "\n";
      TestTree.Delete(Remove_Option_Two);
      TestTree.SanityCheck();

      // Show new results by repeating code
      // Check each inserted after tree is complete
      std::cout << "\n~~~Updated Tree (Method Two)~~~\n";
      std::cout << "(Details in Description)\n\n\n";
      for (int j = 0; j < Size_Option; j++) {
        if (DataInputted[j] == Remove_Option_Two) {
          // do nothing
        } else
             TestTree.GetNodeInfo(DataInputted[j]);
          TestTree.SanityCheck();
      }
      std::cout << "\n";
      // Output the order of the data inserted
      std::cout << "~~~New Order Of Inserted Data~~~\n";
      for (int j = 0; j < Size_Option; j++) {
        if (DataInputted[j] == Remove_Option_Two) {
          // do nothing
        } else
          std::cout << DataInputted[j] << " ";
      }
      std::cout << "\n\n";
      // Output the traversed tree (inorder)
      std::cout << "~~~Final Traverse~~~\n";
      TestTree.Traverse();
      std::cout << "\n";
    } else {
      std::cout << Remove_Option_Two;
      std::cout << " Not found in tree... ending program.\n";
    }
  }
  return 0;
};
// Main Menu()
// Checks If user wants test cases instead
void menu_main(bool& Test_Case, bool& LRresponse) {
  // Declare Variables
  int input = 2;
  int LRinput = 2;

  // Get input
  while (input != 1 && input != 0) {
    std::cout << "~~~ LLRBT Testing! ~~~~\n";
    std::cout << "Would you like to:\n";
    std::cout << "[0]-Look at 5 test runs (shown on pdf)\n";
    std::cout << "[1]-Continue On With Program (Project Specified)\n";
    std::cin >> input;
    if (input != 1 && input != 0)
      std::cout << "Not an option please try again.\n";
    else if (input >= 1)
      Test_Case = 1;
    else
      Test_Case = 0;
  }
  while (LRinput != 1 && LRinput != 0) {
    std::cout << "\n~~~ Rotation Notifcation ~~~~\n";
    std::cout << "(Detail In Description & Method One Only)\n";
    std::cout << "Do you want to display when rotations ";
    std::cout << "occur to make output easier to read?\n";
    std::cout << "[0]- no, I understand that rotations are meant to be "
                 "interpreted by user\n";
    std::cout << "[1]- yes, I would like ";
    std::cout << "program to notify me on rotations\n";
    std::cin >> LRinput;

    if (LRinput != 1 && LRinput != 0)
      std::cout << "Not an option please try again.\n";
    else if (LRinput >= 1)
      LRresponse = 1;
    else
      LRresponse = 0;
  }
};
// Menu Inserting Function
void menu_Insert(int& User_Size, int& Unique) {
  // Output And Get User Input
  while (User_Size == 0) {
    std::cout << "\n~~~ Amount Size ~~~~\n";
    std::cout << "Please select the amount of data";
    std::cout << " you want in the tree: ";
    std::cout << "\n(Note: 10 is project specified)\n";
    std::cin >> User_Size;
    if (User_Size == 0)
      std::cout << "Can't be 0, please try something else...\n";
  }
  // Check If User wants unique values by passing to new function
  while (Unique != 1 && Unique != 0) {
    Unique_Check(Unique);
  }
};

// Remove Function
int menu_Remove(int Arr[], int Size) {
  // Declare Variables
  int Selection = 2;
  int Remove_Option = 0;
  // Get User Input For Delete and check if size inputed is > 4
  while (Selection != 1 && Selection != 0) {
    std::cout << "\n~~~ Removing Element ~~~~\n";
    std::cout << "Would you like to:\n";
    std::cout << "[0]-Choose your own value to delete\n";
    std::cout << "[1]-Delete 4th random insert (project specified)\n";
    std::cin >> Selection;
  }
  if (Selection == 0) {
    std::cout << "Please select what number you would like to remove:\n";
    std::cin >> Remove_Option;
    return Remove_Option;
  }
  if (Selection == 1) {
    if (Size < 4) {
      std::cout << "Size is less than four...\n";
      std::cout << "Will delete first inserted instead\n";
      return Arr[0];
    } else
      return Arr[3];
  }
};

// Unique Check function ()
// Asks if user wants unique data or random data and returns answer
int Unique_Check(int& Unique) {
  while (Unique != 1 && Unique != 0) {
    std::cout << "\n~~~ Data Specification ~~~~\n";
    std::cout << "Please Select What Type Of Data\n";
    std::cout << "[0]-Unique Data\n[1]-Random Data (Project Specified)\n";
    std::cin >> Unique;
    if (Unique != 1 && Unique != 0)
      std::cout << "Not an option please try again.\n";
  }
  return Unique;
};

// Array Unique Function ()
// Fills In array With User's desired Data
void ArrayUnique(int Unq[], int User_Size) {
  int insert = 0;
  for (int i = 0; i < User_Size; i++) {
    std::cout << "Insert element " << i+1 << " :\n";
    std::cin >> insert;
    Unq[i] = insert;
  }
};

// TestCase Function ()
// Displays Pre determined test cases (Refer to Description Page)
void TestCases(bool Left_Right) {
  // Declare Variables with coresponding data
  LeftLeaningRedBlack OneTree;
  int OneData[5] = {5, 2, 9, 1, 8};
  LeftLeaningRedBlack TwoTree;
  int TwoData[5] = {20, 10, 30, 25, 35};
  LeftLeaningRedBlack ThreeTree;
  int ThreeData[7] = {40, 3, 42, 2, 4, 41, 1};
  LeftLeaningRedBlack FourTree;
  int FourData[10] = {37, 68, 42, 9, 2, 18, 13, 89, 0, 21};
  LeftLeaningRedBlack FiveTree;
  int FiveData[10] = {12, 8, 1, 30, 5, 26, 33, 32, 40, 20};

  for (int z = 1; z < 6; z++) {
    std::cout << "~~~~~~Test Case #" << z << "~~~~~~~\n";
    switch (z) {
      default:
        return;
        break;
      case 1:
        std::cout << "\n~~~Inserted ONE~~~\n";
        // Get Method One
        std::cout << "~~~Step By Step Process (Method One) ONE~~~\n";
        std::cout << "Check Description docx for details.\n\n";
        for (int i = 0; i < 5; i++) {
          VoidRef_t ref;
          ref.Key = OneData[i];
          OneTree.Insert(ref, Left_Right);
          OneTree.GetNodeInfo(ref.Key);
        }
        // Get Method Two
        std::cout << "\n~~~Step By Step Process (Method Two) ONE~~~\n";
        std::cout << "Check Description docx for details.\n\n";
        for (int j = 0; j < 5; j++) {
          OneTree.GetNodeInfo(OneData[j]);
        }
        // Inorder Traversal
        std::cout << "\n~~~Traverse ONE~~~\n";
        OneTree.Traverse();
        // Get exact order of how data was inserted
        std::cout << "~~~Order Of Inserted Data ONE~~~\n";
        for (int j = 0; j < 5; j++) {
          std::cout << OneData[j] << " ";
        }
        std::cout << "\n\n";
        break;
      case 2:
        std::cout << "\n~~~Inserted TWO~~~\n";
        // Get Method One
        std::cout << "~~~Step By Step Process (Method One) TWO~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int i = 0; i < 5; i++) {
          VoidRef_t ref;
          ref.Key = TwoData[i];
          TwoTree.Insert(ref, Left_Right);
          TwoTree.GetNodeInfo(ref.Key);
        }
        // Get Method Two
        std::cout << "\n~~~Step By Step Process (Method Two) TWO~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int j = 0; j < 5; j++) {
          TwoTree.GetNodeInfo(TwoData[j]);
        }
        // Inorder Traversal
        std::cout << "\n\n~~~Traverse TWO~~~\n";
        TwoTree.Traverse();
        // Get exact order of how data was inserted
        std::cout << "~~~Order Of Inserted Data TWO~~~\n";
        for (int j = 0; j < 5; j++) {
          std::cout << TwoData[j] << " ";
        }
        std::cout << "\n\n";
        break;
      case 3:
        std::cout << "\n~~~Inserted THREE~~~\n";
        // Get Method One
        std::cout << "~~~Step By Step Process (Method One) THREE~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int i = 0; i < 7; i++) {
          VoidRef_t ref;
          ref.Key = ThreeData[i];
          ThreeTree.Insert(ref, Left_Right);
          ThreeTree.GetNodeInfo(ref.Key);
        }
        // Get Method Two
        std::cout << "\n~~~Step By Step Process (Method Two) THREE~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int j = 0; j < 7; j++) {
          ThreeTree.GetNodeInfo(ThreeData[j]);
        }
        // Inorder Traversal
        std::cout << "\n~~~Traverse THREE~~~\n";
        ThreeTree.Traverse();
        // Get exact order of how data was inserted
        std::cout << "~~~Order Of Inserted Data THREE~~~\n";
        for (int j = 0; j < 7; j++) {
          std::cout << ThreeData[j] << " ";
        }
        std::cout << "\n\n";
        break;
      case 4:
        std::cout << "\n~~~Inserted FOUR~~~\n";
        // Get Method One
        std::cout << "~~~Step By Step Process (Method One) FOUR~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int i = 0; i < 10; i++) {
          VoidRef_t ref;
          ref.Key = FourData[i];
          FourTree.Insert(ref, Left_Right);
          FourTree.GetNodeInfo(ref.Key);
        }
        // Get Method Two
        std::cout << "\n~~~Step By Step Process (Method Two) FOUR~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int j = 0; j < 10; j++) {
          FourTree.GetNodeInfo(FourData[j]);
        }
        // Inorder Traversal
        std::cout << "\n~~~Traverse FOUR~~~\n";
        FourTree.Traverse();
        // Get exact order of how data was inserted
        std::cout << "~~~Order Of Inserted Data FOUR~~~\n";
        for (int j = 0; j < 10; j++) {
          std::cout << FourData[j] << " ";
        }
        std::cout << "\n\n";
        break;
      case 5:
        std::cout << "\n~~~Inserted FIVE~~~\n";
        // Get Method One
        std::cout << "~~~Step By Step Process (Method One) FIVE~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int i = 0; i < 10; i++) {
          VoidRef_t ref;
          ref.Key = FiveData[i];
          FiveTree.Insert(ref, Left_Right);
          FiveTree.GetNodeInfo(ref.Key);
        }
        // Get Method Two
        std::cout << "\n~~~Step By Step Process (Method Two) FIVE~~~\n";
        std::cout << "Check Description docx for details.\n\n\n";
        for (int j = 0; j < 10; j++) {
          FiveTree.GetNodeInfo(FiveData[j]);
        }
        // Inorder Traversal
        std::cout << "\n~~~Traverse FIVE~~~\n";
        FiveTree.Traverse();
        // Get exact order of how data was inserted
        std::cout << "~~~Order Of Inserted Data FIVE~~~\n";
        for (int j = 0; j < 10; j++) {
          std::cout << FiveData[j] << " ";
        }
        std::cout << "\n\n";
        break;
    }
  }
};
