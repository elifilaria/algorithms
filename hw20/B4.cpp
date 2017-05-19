#include <iostream>
using namespace std;

void reorder(int arr[], int n, int i){
	int min = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if (left < n && arr[left] < arr[min]){
		min = left;
	}
	if (right < n && arr[right] < arr[min]){
		min = right;
	}
	if (min != i){
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		reorder(arr, n, min);
	}
}

void heapSort(int arr[], int n){
	for (int i=n/2-1; i>=0; i--){
		reorder(arr,n,i);
	}	
	for (int i=n-1; i>=0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		reorder(arr, i, 0);
	}
}


int main(){
	int arr[] = {5,6,2,1,16,3,7};
	int size = sizeof(arr)/sizeof(int);
	heapSort(arr, size);
	for(int i=0; i<size;i++){
		cout<<arr[i]<<" ";
	}
}
