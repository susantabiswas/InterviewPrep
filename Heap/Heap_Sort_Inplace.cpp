//Inplace heap sort
/*
	with the given array create a heap then delete one by one element
	and add it to the back of the array
*/
//Heap creation for Max heap
#include<iostream>
#include<vector>
using namespace std;

//returns the index of left child
int leftChild(vector<int> &arr,int i, int c){
	if((2*i + 1) >= c)
		return -1;
	return 2*i + 1;
}

//returns the index of right child
int rightChild(vector<int> &arr,int i, int c){
	if((2*i + 2) >= c)
		return -1;
	return 2*i + 2;
}


//for heapifying the heap
void percolateDown( vector<int> &arr, int i, int c){
	if(i >= c && c>0)
		return;
	//find the left and right child
	int l = leftChild(arr,i,c);
	int r = rightChild(arr,i,c);

	int max_index = i;
	//find out which is the max element out of three
	if(l != -1 && arr[l] > arr[i])
		max_index = l;
	if(r != -1 && arr[r] > arr[max_index])
		max_index = r;

	//if the max element is any of its child then percolate down
	if(max_index != i){
		//swap the max child with the parent
		int t = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = t;
		percolateDown(arr, max_index,c);
	}
}


//Heap sort
vector<int> heapSort(vector<int> &arr){
	int c = arr.size() - 1;
	int el ;
	int n = arr.size();

	//make a heap with the array to be sorted
	//by heapifying the array from bottom
	for(int i = (arr.size()-1)/2; i>=0; i--){
		percolateDown(arr,i,c);
	}

	//now remove the elements one by one from the heap
	for(int i = 0; i<arr.size(); i++){
		el = arr[0];
		arr[0] = arr[n - 1 -i];
		arr[n - 1 - i] = el;
		c--;
		percolateDown(arr,0,c);
	}
}


int main(){

	vector<int> arr = {111,23,3,47,5,86,7,18};
	vector<int> res = heapSort(arr);
	cout<<endl<<"Result:\n";
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
