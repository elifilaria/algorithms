#include <iostream>
#include <math.h>
using namespace std;


int fnc(int x)
{
   if (x > 0) {
     return fnc(x-2) + fnc(x-4) + fnc(x-6);
}

   else
     return x;
};


int main()
{
   int x = 70;
   int a = fnc(x);
   cout << a << endl;
}
