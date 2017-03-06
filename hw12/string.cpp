#include <iostream>
using namespace std;
#include <vector>

int binary_search(const vector<string>& sorted_vec, string key) {
   size_t mid, left = 0 ;
   size_t right = sorted_vec.size(); // one position passed the right end
   while (left < right) {
      mid = left + (right - left)/2;
      if (key > sorted_vec[mid]){
          left = mid+1;
      }
      else if (key < sorted_vec[mid]){
        right = mid;
      }
      else {
        return mid;
     }
   }

   return -1;
}

int main()
{
   vector<string> elif = {"aa", "bc", "ef", "gk", "lm", "or", "pp", "st", "uv", "xx"};
   int x = binary_search(elif, "pp");
   cout << x << endl;
}
