#ifndef _node_
#define _node_

class Node {
 private:
  char letter;
  int pri;
  Node* left;
  Node* right;
 public:
  Node(char l, int pri);
  Node(Node* left, Node* right);
  Node(const Node &other);
  Node* getLeft() const;
  Node* getRight() const;
  void display();
  char getLetter() const;
  int getPri() const;
  bool operator<(const Node& other) const;
  bool operator>(const Node& other) const;
};


#endif  // _node_

