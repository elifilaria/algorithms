#include "node.h"
#include <iostream>
using namespace std;

int main()
{
  Node* a = new Node('c', 5);
  Node* b = new Node('d', 6);
  Node c(a, b);
  cout << "c is less than b, expect false " << (&c<b) << endl;
  cout << "a is less than b, expect true " << (a<b) << endl;
  return 0;
}

