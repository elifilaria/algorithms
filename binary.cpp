#include <iostream>
#include <stdlib.h>
using namespace std;

int *initializeArray( int N )
{
  // initialize an array with random values
  int *array = new int[N];
  for ( int i=0; i<N; ++i )
      array[i] = rand()%100;
  return array;
}


void SelSort(int *IntArray, int Count)
{
   int current_ele,search_ele,search_min,temp;

   for (current_ele = 0;current_ele < Count;current_ele++)
          {
             search_min=current_ele;
             // Find index of largest element in unsorted section of elements
             for(search_ele = current_ele+1; search_ele < Count; search_ele++)
                   if(IntArray[search_min] > IntArray[search_ele])
                      search_min=search_ele;

             // Exchange items at position search_max and current_ele
             if (search_min > current_ele)
                {
                 temp=IntArray[search_min];
                 IntArray[search_min]=IntArray[current_ele];
                 IntArray[current_ele]=temp;
                }
          }
}

// Code for BinarySearch
int BinarySearch(int *IntArray, int Low, int High, int Target)
{
   int Mid, Difference;

   while (Low <= High)
   {
      Mid = (Low + High) / 2;
      Difference = IntArray[Mid] - Target;

      if (Difference == 0)         // IntArray[Mid] == Target
         return Mid;
      else if (Difference < 0)     // IntArray[Mid] < Target
         Low = Mid + 1;
      else 
         High = Mid - 1;
 }

   return -1;   // If reach here, Target was not found.
}

int main()
{
   int *arr = initializeArray(100);
   SelSort(arr, 100);
   for (int i = 0; i < 100; ++i) {
       cout << arr[i] << endl;
}   //int arr [10] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
   int x = BinarySearch(arr, 0, 100, 8);
   cout << x << endl;
}
