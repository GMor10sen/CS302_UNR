#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BinaryNode.cpp"
#include "BinaryNodeTree.cpp"
#include "BinarySearchTree.cpp"

// Fills Tree with random data
template <typename DataType>
void FillRandomBinary(BinarySearchTree<DataType> &TreeInputted, int amount);
template <typename DataType>
void FillRandomNode(BinaryNodeTree<DataType> &TreeInputted, int amount);
// Visit Element function to display data
void VistingElement(auto &DataElement);
// Functions to get user input that vary tests
int Menu(int &Size);
bool Display();

int main() {
  // Used To Make Random Each Time
  std::srand(std::time(nullptr));
  // Create Variales
  BinarySearchTree<int> TestingBinaryTree;
  BinaryNodeTree<int> TestingNodeTree;
  int DataTest = 0;
  int DataEntry = 0;
  int sizeChoice = 0;
  // Get Menu Options
  int Input = Menu(sizeChoice);
  if (Input == 1 || Input == 3) {
    // Notify User On tests
    std::cout << "xXx Testing Binary Search Tree xXx\n";
    // call function that will fill tree
    FillRandomBinary(TestingBinaryTree, sizeChoice);
    // Call function that outputs the height
    std::cout << "~~~ Testing Binary Search Tree Height Function ~~~\nHeight "
                 "Of Tree is: ";
    std::cout << TestingBinaryTree.getHeight();
    std::cout << "\n\n";
    // Preorder Test
    std::cout << "~~~ PreOrder Traversal Binary Search Tree Test ~~~\n";
    TestingBinaryTree.preorderTraverse(VistingElement);
    std::cout << "\n";
    // InOrder Test
    std::cout << "~~~ InOrder Traversal Binary Search Tree Test ~~~\n";
    TestingBinaryTree.inorderTraverse(VistingElement);
    std::cout << "\n";
    // Post Order Test
    std::cout << "~~~ PostOrder Traversal Binary Search Tree Test ~~~\n";
    TestingBinaryTree.postorderTraverse(VistingElement);
    std::cout << "\n";
    // Get Number Of Nodes
    std::cout << "~~~ Test Get Node Binary Search Tree ~~~\nNumber of nodes in "
                 "tree is: ";
    std::cout << TestingBinaryTree.getNumberOfNodes();
    std::cout << "\n";
    // Test Remove
    std::cout << "~~~ Remove Test Binary Search Tree ~~~\n";
    std::cout << "Please Enter an item to remove: ";
    std::cin >> DataTest;
    if (TestingBinaryTree.remove(DataTest))
      std::cout << "Removed " << DataTest << "\n";
    else
      std::cout << "Could Not Remove " << DataTest << "\n";
    // Preorder Test
    std::cout
        << "~~~ Binary Search Tree PreOrder Traversal Test After Remove ~~~\n";
    TestingBinaryTree.preorderTraverse(VistingElement);
    std::cout << "\n";
    // InOrder Test
    std::cout
        << "~~~ Binary Search Tree InOrder Traversal Test After Remove ~~~\n";
    TestingBinaryTree.inorderTraverse(VistingElement);
    std::cout << "\n";
    // Post Order Test
    std::cout
        << "~~~ Binary Search Tree PostOrder Traversal Test After Remove ~~~\n";
    TestingBinaryTree.postorderTraverse(VistingElement);
    std::cout << "\n";
    // getEntry and contains Test
    std::cout << "~~~ Get Entry/Contains Test Binary Search Tree ~~~\n";
    std::cout << "Please Enter an item to retrive: ";
    std::cin >> DataTest;
    if (TestingBinaryTree.contains(DataTest)) {
      DataEntry = TestingBinaryTree.getEntry(DataTest);
      std::cout << DataEntry << " Was retrived.\n";
    } else
      std::cout << DataTest << " not in Tree...\n";
    // Empty Test
    std::cout << "~~~ Empty Test Before Clear Binary Search Tree ~~~\n";
    if (TestingBinaryTree.isEmpty())
      std::cout << "This tree is empty.\n";
    else
      std::cout << "This tree is not empty.\n\n";
    // Clear Test
    std::cout << "~~~ Clear Test Binary Search Tree ~~~\n";
    TestingBinaryTree.clear();
    std::cout << "Clear Function Called\n\n";
    // Empty Test
    std::cout << "~~~ Binary Search Tree Empty Test After Clear ~~~\n";
    if (TestingBinaryTree.isEmpty())
      std::cout << "This tree is empty.\n";
    else
      std::cout << "This tree is not empty.\n";
    std::cout << "\n\n";
  }
  if (Input == 2 || Input == 3) {
    // Declare Variable
    bool DChoice = 0;
    // Notify User On tests
    std::cout << "\nxXx Testing Binary Node Tree xXx\n";
    // call function that will fill tree
    FillRandomNode(TestingNodeTree, sizeChoice);
    // Call function that outputs the height
    std::cout << "~~~ Testing Binary Node Tree Height Function ~~~\nHeight Of "
                 "Tree is: ";
    std::cout << TestingNodeTree.getHeight();
    std::cout << "\n\n";
    // Get User Input
    DChoice = Display();
    if (DChoice) {
      // Preorder Test
      std::cout << "~~~ PreOrder Traversal Binary Node Tree Test ~~~\n";
      TestingNodeTree.preorderTraverse(VistingElement);
      std::cout << ".\n";
      // InOrder Test
      std::cout << "~~~ InOrder Traversal Binary Node Tree Test ~~~\n";
      TestingNodeTree.inorderTraverse(VistingElement);
      std::cout << ".\n";
      // Post Order Test
      std::cout << "~~~ PostOrder Traversal Binary Node Tree Test ~~~\n";
      TestingNodeTree.postorderTraverse(VistingElement);
      std::cout << ".\n";
    }
    // Get Number Of Nodes
    std::cout << "~~~ Test Binary Node Tree Get Node ~~~\nNumber of nodes in "
                 "tree is: ";
    std::cout << TestingNodeTree.getNumberOfNodes();
    std::cout << "\n";
    // Test Remove
    std::cout << "~~~ Binary Node Tree Remove Test ~~~\n";
    std::cout << "Please Enter an item to remove: ";
    std::cin >> DataTest;
    if (TestingNodeTree.remove(DataTest))
      std::cout << "Removed " << DataTest << "\n";
    else
      std::cout << "Could Not Remove " << DataTest << "\n";
    if (DChoice) {
      // Preorder Test
      std::cout
          << "~~~ Binary Node Tree PreOrder Traversal Test After Remove ~~~\n";
      TestingNodeTree.preorderTraverse(VistingElement);
      std::cout << "\n";
      // InOrder Test
      std::cout
          << "~~~ Binary Node Tree InOrder Traversal Test After Remove ~~~\n";
      TestingNodeTree.inorderTraverse(VistingElement);
      std::cout << "\n";
      // Post Order Test
      std::cout
          << "~~~ Binary Node Tree PostOrder Traversal Test After Remove ~~~\n";
      TestingNodeTree.postorderTraverse(VistingElement);
      std::cout << "\n";
    }
    // getEntry Test
    std::cout << "~~~ Get Entry/Contains Test Binary Node Tree ~~~\n";
    std::cout << "Please Enter an item to retrive: ";
    std::cin >> DataTest;
    if (TestingNodeTree.contains(DataTest)) {
      DataEntry = TestingNodeTree.getEntry(DataTest);
      std::cout << DataEntry << " Was retrived.\n";
    } else
      std::cout << DataTest << " not in Tree...\n";
    // Empty Test
    std::cout << "~~~ Binary Node Tree Empty Test Before Clear ~~~\n";
    if (TestingNodeTree.isEmpty())
      std::cout << "This tree is empty.\n";
    else
      std::cout << "This tree is not empty.\n\n";
    // Clear Test
    std::cout << "~~~ Binary Node Tree Clear Test ~~~\n";
    TestingNodeTree.clear();
    std::cout << "Clear Function Called\n\n";
    // Empty Test
    std::cout << "~~~ Binary Node Tree Empty Test After Clear  ~~~\n";
    if (TestingNodeTree.isEmpty())
      std::cout << "This tree is empty.\n";
    else
      std::cout << "This tree is not empty.\n";
    std::cout << "\n\n";
  }
  return 0;
}

// Function That Fills Tree With Random Ints
template <typename DataType>
void FillRandomBinary(BinarySearchTree<DataType> &TreeInputted, int amount) {
  // Declare Variables
  int TwoHundred = 200;
  int random_int = 0;
  int i = 0;
  // Notify User
  std::cout << "~~~ Add Test ~~~\n\nFilled Tree with : ";
  // Create Loop Where Tree is filled
  while (i < amount) {
    random_int = (rand() % TwoHundred) + 1;
    // Use if statement to make sure value does not already
    // exist in tree so values are uniqe
    if (!TreeInputted.contains(random_int)) {
      std::cout << random_int;
      TreeInputted.add(random_int);
      // Use if statement to get proper commas
      if (i < amount - 1) std::cout << ",";
      i++;
    }
  }
  std::cout << ".\n\n";
};
// Function That Fills Tree With Random Ints
template <typename DataType>
void FillRandomNode(BinaryNodeTree<DataType> &TreeInputted, int amount) {
  // Declare Variables
  int TwoHundred = 200;
  int random_int = 0;
  int i = 0;
  // Notify User
  std::cout << "~~~ Add Test ~~~\n\nFilled Tree with : ";
  // Create Loop Where Tree is filled
  while (i < amount) {
    random_int = (rand() % TwoHundred) + 1;
    // Use if statement to make sure value does not already
    // exist in tree so values are uniqe
    if (!TreeInputted.contains(random_int)) {
      std::cout << random_int;
      TreeInputted.add(random_int);
      // Use if statement to get proper commas
      if (i < amount - 1) std::cout << ",";
      i++;
    }
  }
  std::cout << ".\n\n";
};
// Function That 'Visits' each item for traversal
void VistingElement(auto &DataElement)
 { 
        std::cout << DataElement << ", "; 
 };
// Menu
int Menu(int &Size) {
  // Declare Varibles
  bool Loop = 1;
  int Choice = 0;
  // Loop To Until Input Achieved
  while (Loop) {
    std::cout << "~#~#~# TREE TESTING #~#~#~\n";
    std::cout << "Please Choose From The Following:\n";
    std::cout << "[1] Only Binary Search Tree (Project Specified)\n";
    std::cout << "[2] Only Binary Node Tree (Reason For Option In Lab File)\n";
    std::cout << "[3] Both\n";
    // Get Input
    std::cin >> Choice;
    // If Input Is Choice Option Stop Loop
    if (Choice < 4 && Choice > 0)
      Loop = 0;
    else
      std::cout << "Not an option, please try again...\n";
  }
  std::cout << "\nGreat, Now how many nodes would you like to try?\n";
  std::cout << "Please note '100' is the project specified amount:\n";
  std::cin >> Size;

  return Choice;
};
// Display Choice
bool Display() {
  int DChoice = 0;
  std::cout << "Do you want to display traversals of Node Tree?\n";
  std::cout << "Note that this is ~~NOT~~ a Binary Search Tree\nMeaning these "
               "values are out of order\n\n";
  std::cout << "[1] - Yes, I want to see the traverse values in ~~BNT~~\n";
  std::cout << "[0] - No\n";
  std::cin >> DChoice;
  return DChoice;
}
