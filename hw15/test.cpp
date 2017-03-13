#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct node{
    int data[3];
    node* next;
};
struct linkedList{
 	node *startnode;
 	int max[3];
 	vector<node* > tracker;
 	linkedList(){
 		startnode = new node;
		max[0] = 10;
		max[1] = 7;
		max[2] = 4;
 		startnode->data[0] = 0;
 		startnode->data[1] = 7;
 		startnode->data[2] = 4;
 	};
	node pour(node* state, int i, int j){
	 	int A = state->data[i];
	 	int B = state->data[j];
	 	int change = min(A, max[j]-B);
	 	A-=change;
	 	B+=change;
	 	node next = *state;
	 	next.data[i]=A;
	 	next.data[j]=B;
	 	return next;
	 }
	void printNode(node* n){
		for(int i = 0; i < 3; i++){
			cout << n->data[i]<<" ";
		}
		cout << endl;
	}
	bool found(node* find){
		for(vector<node*>::iterator i = tracker.begin(); i != tracker.end(); i++) {
			if (equal(begin(find->data), end(find->data), begin((*i)->data)))
				return true;
		}
		return false;
	}
	void DFS(){
		explore(startnode);
	}
	void explore(node* state){
		printNode(state);
		tracker.push_back(state);

                while(state->data[1] != 2 && state->data[2] != 2){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					node* newState = new node;
					*newState = pour(state,i,j);
					if(i!=j && !found(newState)){
						explore(newState);
					}


					}



			}

}
	}
};
int main(){
 	linkedList l1;
 	l1.DFS();

 }
