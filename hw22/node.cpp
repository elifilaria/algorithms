#include "node.h"
#include <iostream>
using namespace std;

Node::Node(char l, int pri)
{
  this->letter = l;
  this->pri = pri;
  this->left=0;
  this->right=0;
}

Node::Node(const Node &other)
{
  if (other.getLeft()!=0)
    {
      left = new Node(*other.getLeft());
      right = new Node(*other.getRight());
    }
  this->letter = other.getLetter();
  this->pri = other.getPri();
}

Node::Node(Node* a, Node* b)
{
	if(a > b){
	  this->left = b;
	  this->right = a;
	}
	else{
	  this->left = a;
	  this->right = b;
	}
	this->pri=left->getPri()+right->getPri();
	this->letter=0;
}

Node* Node::getLeft() const
{
  return left;
}

Node* Node::getRight() const
{
  return right;
}

void Node::display()
{
	if(getLetter()){
		cout << getLetter() << endl;
	}
	else{
		left->display();
		right->display();
	}
}

char Node::getLetter() const
{
  return letter;
}

int Node::getPri() const
{
  return pri;
}

bool operator< (const Node& a, const Node& b)
{
  return a.getPri() < b.getPri();
}

bool Node::operator< (const Node& other) const
{
  return this->getPri() < other.getPri();
}

bool Node::operator> (const Node& other) const
{
  return this->getPri() > other.getPri();
}

