// Insertion Sort used to quick sort 
void InsertionSortType:: insertionSort (int Inital_Placement, int Final_Placment)
{
 // 
  for (int unsorted_element = 1; unsorted_element < Final_Placment; unsorted_element++)
  {
     // set a temp item to hold the next element & get a new index for the sorted region
       int nextItem = Array[unsorted_element]; 
       int Index_Sorted_Region = unsorted_element; 

    // While out of order switch the elements of the array to proper locations
       while ((Index_Sorted_Region > 0) && (Array[Index_Sorted_Region-1] > nextItem))
       {        QuickComparisons++;
                QuickSwap++; 
		Array[Index_Sorted_Region] = Array[Index_Sorted_Region-1];
                Index_Sorted_Region --; 
       }
    // Have the next unsorted element be in order   
       Array [Index_Sorted_Region] = nextItem; 
  }
}
