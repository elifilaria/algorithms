#include <iostream>

using namespace std;

int main() {
   int n = 10;
   int* array = new int[n];
   for(int i=0; i<n; i++){
      array[i] = (rand()%100)+1;
   }
   for(int x=0; x<n; x++){
      int index_of_min = x;
      for(int y=x; y<n; y++){
          if(array[index_of_min]<array[y]){
             index_of_min = y;
          }
      }
      int temp = array[x];
      array[x] = array[index_of_min];
      array[index_of_min] = temp;
   }
   for (int z = n-1; z >= 0; z--)
      cout << array[z];
   cout << endl;
}

