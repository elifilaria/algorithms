#include <iostream>
#include <stack>
using namespace std;




class Node {
  int name;
  Node* childNodes;
  bool visited;

  Node constructor(int, Node*) {
    this->name = name;
    this->childNodes = childNodes;
    this->visited = false;
  }

  Node dfs(Node);
}



Node dfs(Node s) {
  let stack = [];
  stack.push(s);
  stackLoop: while (stack.length) {
    let u = stack[stack.length - 1]; // peek
    if (!u.visited) {
      u.visited = true; // grey - visited
      yield u;
    }

    for (let v of u.childNodes) {
      if (!v.visited) {
        stack.push(v);
        continue stackLoop;
      }
    }

    stack.pop(); // black - all reachable descendants were processed 
  }    
  return s;
}


int main() {


	Node x(10, y);
        Node y(7, z);
	Node z(4, x);
        cout << dfs(x) << endl;
}
