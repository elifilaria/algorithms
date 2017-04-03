#include <iostream>
#include <vector>
using namespace std;

class binaryHeap{
public:
	vector<int>* bh;
	int size;
	int num_elements;

	binaryHeap(int s){
		size = s;
		num_elements = 0;
		bh = new vector<int>[size];
	}

	int parent(int i){
		return (i-1)/2;
	}

	int leftChild(int i){
		return 2*i + 1;
	}

	int rightChild(int i){
		return 2*i + 2;
	}

	void insert(int vertex, int distance){
		num_elements++;
		int last = num_elements - 1;
		bh[last].push_back(vertex);
		bh[last].push_back(distance);
		while (last != 0 && bh[parent(last)][1] > bh[last][1]){
			int temp = bh[parent(last)][1];
			bh[parent(last)][1] = bh[last][1];
			bh[last][1] = temp;
			temp = bh[last][0];
			bh[last][0] = bh[parent(last)][0];
			bh[parent(last)][0] = temp;
			last = parent(last);
		}
	}

	int deleteMin(){
		vector<int> root = bh[0];
		bh[0] = bh[num_elements - 1];
		num_elements = num_elements - 1;
		reorder(0);
		return root[1];
	}

	void reorder(int i){
		int l = leftChild(i);
		int r = rightChild(i);
		int min = i;
		if (l<num_elements && bh[l][1] < bh[i][1])
        	min = l;
    	if (r<num_elements && bh[r][1] < bh[min][1])
        	min = r;
    	if (min != i)
    		{
        		int temp = bh[min][1];
				bh[min][1] = bh[i][1];
				bh[i][1] = temp;
				temp = bh[i][0];
				bh[i][0] = bh[min][0];
				bh[min][0] = temp;
        		reorder(min);
    		}
	}
};

int main(){
	binaryHeap bh1(6);
	bh1.insert(0,8);
	bh1.insert(1,7);
	bh1.insert(3,15);
	bh1.insert(4,4);
	for(int i=0; i<bh1.num_elements; i++){
		cout<<bh1.bh[i][0]<<" "<< bh1.bh[i][1]<<endl;
	}
	cout<<bh1.deleteMin()<<"delete"<<endl;
	for(int i=0; i<bh1.num_elements; i++){
		cout<<bh1.bh[i][0]<<" "<< bh1.bh[i][1]<<endl;
	}
	cout<<bh1.deleteMin()<<"deleted"<<endl;
	for(int i=0; i<bh1.num_elements; i++){
		cout<<bh1.bh[i][0]<<" "<< bh1.bh[i][1]<<endl;
	}
	cout<<bh1.deleteMin()<<"deleted"<<endl;
	cout<<bh1.deleteMin()<<"deleted"<<endl;
	for(int i=0; i<bh1.num_elements; i++){
		cout<<bh1.bh[i][0]<<endl;
	}
}
