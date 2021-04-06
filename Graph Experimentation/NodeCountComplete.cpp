#include <iostream>
#include <math.h> 



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Method #2 
//
int countingNodes (TreeNode* root)
{

  // Decalre some variables 
   TreeNode*LeftDepth =root;
   TreeNode*RightDepth =root;
   int LDepth_Count = 0;
   int RDepth_Count = 0; 
   int Inital_Depth = 0; 
   int Count = 0;   

  // The Tree is empty 
   if (root == nullptr)
     return 0; 
  
  // Get the left depth count 
   while(LeftDepth != nullptr)
   {
    LDepth_Count ++; 
    LeftDepth = LeftDepth -> left; 

   }
 // Get the right depth count 
   while(RightDepth != nullptr)
   {
    RDepth_Count ++; 
    RightDepth = RightDepth -> right; 

   }
 // If depths are equal it is full tree!
  if (LDepth_Count == RDepth_Count)
  {
     Inital_Depth = LDepth_Count; 
     return NodesPredetermined(Inital_Depth); 
  }
  else 
  {
    // if depths are not equal keep going down until 
    // a full tree is found then add up the sub nodes 
    //       left side            +   root +    rightside 
    return countingNodes(root->right) + 1 + countingNodes(root->left)
  }
};

// Returns the total amount of nodes 
int NodesPredetermined (int depthcount)
{
  // Use EQ for number of nodes in full tree
  // which is : (2^d) - 1
   return pow(2,depthcount) - 1; 
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Method #1 Taught By Instructor 
//
int countNodes (TreeNode *root)
{
  // First the depth needs to be calculated
  // if this is done we know the node count
  // before the final level
  // which is : (2^d) - 1
  
  std::cout << "Calculating Depth...\n";
  int depth_count = 0; 
 
  // Traversing down the left side until nothing found
  // Choose left because nodes build from left to right
  while (current_node != nullptr)
  {
    depth_count= depth_count + 1; 
    node = node->left; 
  }
  // Inform user on result 
  std::cout << "Depth is: " << depth_count << "\n";
  
  // Next need to get the potential nodes on the last level
  // Can do this by dividing up checking a possible range 
   int Bottom_Range = std::pow(2,d-1); // index set at 2^(d-1) 
   // could set bottom range to zero so you don't have to 
   // subtract in the end like so 
   // int Bottom_Range = 0;
   int Top_Range = std::pow(2,d) -1; // index set on last level
   // However top range will always be the last node 
   while (low <= hi)
   {
   // typical binary search but this time checking with each run 
   // which reduces the range we need to look for leaf
   // Goal is to find leaf placement and remove
     int mid = Bottom_Range + (Top_Range-Bottom_Range) /2;
   // If the node we are looking for exists 
   // then we can increment the left side of our range
   // because we want to check leafs after
   // other wise we know there are no leafs
   // after a null to we shorten right hand range 
     if (existLeaf(root, d, mid) == 1)
      Bottom_Range = mid + 1; // shortens range on left 
     else 
       Top_Range = mid - 1;// shortens range on right side  
   }
       //  Nodes before known level +  Nodes after known level 
       // Bottom_Range - pow(2, d - 1) works as nodes on last level
       // because our bottom range is the number of known leafs
       // combined with the node count of other levels (which is why 
       // we subtract) if bottom_range set to zero this is not the case
   return (pow(2, d - 1) - 1) + (Bottom_Range - pow(2, d - 1));
};

bool existLeaf(root, d, mid)
{
  // make new search 
   int depth = 0; 
   int lower = pow(2,d-1);
   // Once again,
   // could set bottom range to zero so you don't have to 
   // subtract in the end like so 
   // int lower = 0;
   int upper = pow(2,d) -1; 

  // Want to traverse tree down to the last layer
  // to check if node exsits  
  do {
     // Use Check to determine which was to traverse 
     // ex) go left or right on a node
     // As more leafs are found low will increment
     // and check will change to go right eventually 
     // or high will decrement and visa versea 
     // either way this code is checking how to 
     // traverse to find an count nodes
      double check = ( ( (double)mid-low) / (hi-low) );
      if (check < 0.5) 
      {
        root = root -> left; 
        hi = low + (hi - low) /2; 
      }
      else
      {
        root = root ->right;
        low = low + (hi -low) / 2 + 1;
      }
      i++;
   while (level < d-1);
     return (root != nullptr);
}; 

*/ 
}
