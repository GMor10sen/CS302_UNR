#include <iostream>

void Count_Down (int n); 
int p (int x);

int main ()
{
   std::cout << "Count down: \n"; 
   int Numbers = 5;
   Count_Down (Numbers); 
   std::cout << "\n"; 
   for (int i = 1; i < 10; i ++)
   {
      std::cout << i << ": " << p(i) << "\n";
   } 
};

void Count_Down (int n)
{
  // Base case is the last number 
   if (n == 1)
   {
     std::cout << n << "."; 
     return; 
   }
   //Count_Down (n-1); // to count 1 to n  
   std::cout << n << ", "; 
   Count_Down (n-1); // to count n to 1 
};

int p(int x)
{
  if (x <= 3) 
    return x; 
  else 
    return p(x-1) * p(x-3); 
 
}
