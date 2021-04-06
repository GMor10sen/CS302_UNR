#include <iostream> 

void TowerOfHanoi_Method_One (int n, char from_rod , char to_rod, char aux_rod);
void TowerOfHanoi_Method_Two (int n, char from_rod , char to_rod, char aux_rod);

int main () 
{
 // Declare Vairbales 
  char From_Input;
  char Aux_Input; 
  char To_Input; 
  int Number_Of_Disks = 0;
 // Get user input 
  std::cout << "Input Number of disks:\n";
  std::cin >>  Number_Of_Disks;
  std::cout << "Input Rightmost Rod Name:\n";
  std::cin >>  From_Input; 
  std::cout << "Input Middle Rod Name:\n";
  std::cin >>  Aux_Input; 
  std::cout << "Input Leftmost Rod Name:\n";
  std::cin >>  To_Input;  
 // Call function
  std::cout << "~~~Method One~~~"; 
  TowerOfHanoi_Method_One (Number_Of_Disks, From_Input, To_Input, Aux_Input ); 
  std::cout << "\n~~~Method Two~~~";
  TowerOfHanoi_Method_Two (Number_Of_Disks, From_Input, To_Input, Aux_Input ); 
  std::cout << "\n";
return 0; 
};

void TowerOfHanoi_Method_One (int n, char from_rod , char to_rod, char aux_rod)
{
   // Base case would be at the last disk
   // Depending on the recurive call it is placed on a different rod
   // This function is O(2^n) because each new disk doubles amount of moves
    if (n == 1)
     {
       std::cout << "\nMove disk " << n;
       std::cout << " from rod " << from_rod << " to rod " << to_rod;
       return; 
     }

   // 1st Recall function: 
   // This function continously swaps the to-rod and aux-rod  
   // Meaning that a second call of this function will work as
   // just like the inital function input. This means the recursive call
   // creates good time complexity by reducing the size of the code because it accounts  
   // for the idea that a bigger disk can't be placed on a smaller disk by swaping the to and aux rod each time.
   // because of the parameter of this code it is noted that n-1 disks are moved from the 
   // from-rod to the auxillary rod. 
   // If recursive calls were not allowed then a programmer would have to have a counter that
   // would either move the disk from the from-rod to the aux-rod or from the from-rod to the to-rod   
   // depending on if the counter was odd or even 
    
        TowerOfHanoi_Method_One (n-1, from_rod, aux_rod, to_rod);
      // Output of this will move the very largest disk (of current call) to the goal 
        std::cout << "\nMove disk " << n;
        std::cout << " from rod " << from_rod << " to rod " << to_rod;

    // 2nd Recall function: 
    // This function continously swaps the from rod and the to rod 
    // However it also works in tandum with the 1st Recursive call
    // Allowing for the code to be reduced significantly 
    // This call takes care of the system after n-1 disks are moved to a specific rod
    // For example if n-1 disks are already moved to the auxiliary rod as mentioned in 
    // the previous comment, thus in this system one is moving those n-1 rods from the aux-rod to the goal rod
        TowerOfHanoi_Method_One (n-1, aux_rod, to_rod, from_rod);
};

void TowerOfHanoi_Method_Two (int n, char from_rod , char to_rod, char aux_rod)
{
  if (n >= 1)
  {
  // 1st Recall function: 
   // This function continously swaps the to-rod and aux-rod  
   // Meaning that a second call of this function will work as
   // just like the inital function input. This means the recursive call
   // creates good time complexity by reducing the size of the code because it accounts  
   // for the idea that a bigger disk can't be placed on a smaller disk by swaping the to and aux rod each time.
   // because of the parameter of this code it is noted that n-1 disks are moved from the 
   // from-rod to the auxillary rod. 
   // If recursive calls were not allowed then a programmer would have to have a counter that
   // would either move the disk from the from-rod to the aux-rod or from the from-rod to the to-rod   
   // depending on if the counter was odd or even 
    TowerOfHanoi_Method_Two (n-1, from_rod , aux_rod, to_rod); 
   // Output of this will move the very largest disk (of current call) to the goal 
    std::cout << "\nMove disk " << n;
    std::cout << " from rod " << from_rod << " to rod " << to_rod;
   // 2nd Recall function: 
    // This function continously swaps the from rod and the to rod 
    // However it also works in tandum with the 1st Recursive call
    // Allowing for the code to be reduced significantly 
    // This call takes care of the system after n-1 disks are moved to a specific rod
    // For example if n-1 disks are already moved to the auxiliary rod as mentioned in 
    // the previous comment, thus in this system one is moving those n-1 rods from the aux-rod to the goal rod
    TowerOfHanoi_Method_Two (n-1, aux_rod , to_rod, from_rod);
  }

}
