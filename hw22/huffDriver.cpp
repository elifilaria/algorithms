#include "node.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;


void bin(ofstream* f, Node* top, string running)
{
	if (top->getLeft()!=NULL)
	{
		bin(f, top->getLeft(), running+"0");
		bin(f, top->getRight(), running+"1");
	}
	else 
	{
		*f << top->getLetter() << " " << running << endl;
	}
}
class Compare {
public:
  bool operator() (Node* lhs, Node* rhs)
  {
    return (*lhs)>(*rhs);
  }

};
Node* huff(map <char,int> input){
	priority_queue<Node*, vector<Node*>, Compare> pq;
	
	int mapSize = 0;
	for (map<char, int>::iterator iter = input.begin(); iter != input.end(); iter++)
	{
		//For display:
	    // cout << "Key: " << iter->first << endl << "Values:" << endl;
	    // typedef list<string>::const_iterator ListIterator;
	    // for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
	    //     cout << " " << *list_iter << endl;
		Node* temp = new Node(iter->first, iter->second);
		pq.push(temp);
		mapSize++;
	}

	while(pq.size()>1){
		Node* a = pq.top();pq.pop();
		Node* b = pq.top();pq.pop();
		//cout << "node a: ";a->display();
		//cout << "node b: ";b->display();
		Node* target = new Node(a,b);
		//cout << "parent of a & b: " << target->getPri() << endl; target->display();
		//target->display();
		pq.push(target);
	}
	Node* top = pq.top();
	ofstream f("output.txt");
	bin(&f, top, "");
	return top;
}	

void decode(Node* top, string binary)
{
	int counter = 0; Node* temp;
	while (counter < binary.size())
	{
		temp = top;
		while (temp->getLetter()==0)
		{
			if (binary.compare(counter, 1, "1")==0)
				temp = temp->getRight();
			else
				temp = temp->getLeft();
			counter++;
		}
		cout << temp->getLetter();
	}
	cout << endl;

}

int main()
{
	ifstream f("input.txt");
	char c;
	map <char,int> input;

	//Make input characters with associated frequency
	while ( f.get(c) ){
		if (c != '\n') {
			if(input.count(c) > 0){
				input[c] += 1;
			}
			else{
				input[c] = 1;
		}
	}
}

	string bnry="010110111";
	decode(huff(input), bnry);
	return 0;
}

