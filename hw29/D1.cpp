#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {
  int* arr;
  arr = new int[5];
  for (int i = 0; i < 5; i++) {
    arr[i] = 0;
  }
  double highest_sum = 0.0;
  for (int x1 = 1; x1 < 21; x1++) {
    for (int x2 = 1; x2 < 21; x2++) {
      for (int x3 = 1; x3 < 21; x3++) {
	for (int x4 = 1; x4 < 21; x4++) {
	  for (int x5 = 1; x5 < 21; x5++) {
	    if (x1 + x2 + x3 + x4 + x5 == 21) {
	      double ans1 = x1/21;
	      double ans2 = (x2*x2)/450;
	      double ans3 = (sqrt(x3))/(sqrt(21));
	      double ans4 = .5*(log10(x4));
	      double ans5 = (pow(1.2,x5))/50;
	      if (x5 == 0)
		ans5 = 0;
	      if (x4 == 0)
		ans4 = 0;
	      double sum1 = ans1+ans2+ans3+ans4+ans5;
	      if (sum1 > highest_sum) {
		arr[0] = x1;
		arr[1] = x2;
		arr[2] = x3;
		arr[3] = x4;
		arr[4] = x5;
		highest_sum = sum1;
		cout << "Highest Sum: " << highest_sum << endl;
		cout << "People Involved: ";
		for (int i = 0; i < 5; i++) {
		  cout << arr[i] << ",";
		}
		cout << endl;
	      }
	      /*cout << "Answer found: (" << ans1 << "," << ans2 << "," << ans3 << "," << ans4 << "," << ans5 << ")." << endl;
		cout << "Number of People: (" << x1 << "," << x2 << "," << x3 << "," << x4 << "," << x5 << ")." << endl;*/
	    }
	  }
	}
      }
    }
  }
  cout << "Highest Sum: " << highest_sum << endl;
  cout << "People Involved: ";
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << ",";
  }
  cout << endl;
}
