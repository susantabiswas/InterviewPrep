//Heap creation for Max heap
#include<iostream>
#include<vector>
using namespace std;

//structure for heap
struct Heap{
	vector<int> arr;
	//total capacity of heap
	int capacity;
	//current size of heap
	int heap_count;
	//min or max heap,0 for min and 1 for max
	bool type;
};

//for creating heap object
Heap* createHeap(int n, bool type){
	Heap* h = new Heap;

	if(h == NULL){
		cout<<"Mem error\n";
		return NULL;
	}

	//ini the different values
	h->heap_count = 0;
	h->capacity = n;
	h->type = type;

	//create the array
	h->arr.resize(n);
	return h;
}

//for resizing the heap
void resizeHeap(Heap* h){
	//copy the old array
	vector<int> old_array(h->arr.begin(), h->arr.end());
	//double the capacity
	h->arr.resize(h->capacity*2);

	//copy old elements back
	for (int i = 0; i < h->heap_count; ++i)
	{
		h->arr[i] = old_array[i];
	}
	h->capacity = h->capacity*2;
	//delete the old array
	old_array.erase(old_array.begin(), old_array.end());
}

//returns the index of left child
int leftChild(Heap* h, int i){
	if(h == NULL || (2*i + 1) >= h->heap_count)
		return -1;
	return 2*i + 1;
}

//returns the index of right child
int rightChild(Heap* h, int i){
	if(h == NULL || (2*i + 2) >= h->heap_count)
		return -1;
	return 2*i + 2;
}

//returns the index of parent
int parent(Heap* h, int i){
	if(h == NULL || i <= 0 || i>h->heap_count)
		return -1;
	return (i - 1)/2;
}

//for heapifying the heap
void percolateDown(Heap* h, int i){
	if(h == NULL || i >= h->heap_count)
		return;
	//find the left and right child
	int l = leftChild(h,i);
	int r = rightChild(h,i);

	int max_index = i;
	//find out which is the max element out of three
	if(l != -1 && h->arr[l] > h->arr[i])
		max_index = l;
	if(r != -1 && h->arr[r] > h->arr[max_index])
		max_index = r;

	//if the max element is any of its child then percolate down
	if(max_index != i){
		//swap the max child with the parent
		int t = h->arr[i];
		h->arr[i] = h->arr[max_index];
		h->arr[max_index] = t;
		percolateDown(h,max_index);
	}

}

//for creating heap from an array
Heap* buildHeap(vector<int> in_arr){

	//create heap
	Heap *h = createHeap(20,1);

	if(h == NULL || in_arr.size()<=0)
		return NULL;
	//check if the heap capacity is enough or not
	while(h->capacity < in_arr.size())
		resizeHeap(h);

	//copy the array elements into heap array
	for (int i = 0; i < in_arr.size(); ++i)
	{
		h->arr[i] = in_arr[i];
	}

	//update count value
	h->heap_count = h->arr.size();

	//now we need to heapify the array
	//we may ignore the leaf nodes so we start from the first
	//non-leaf node
	int i = (h->heap_count-1)/2;
	for(; i>=0 ;i--){
		percolateDown(h,i);
	}
	return h;
}

//returns the max element
int getMax(Heap* h){
	if(h == NULL || h->heap_count <= 0)
		return -1;
	return h->arr[0];
}

//displays the array
void disp(Heap* h){
	for (int i = 0; i < h->heap_count; ++i)
	{
		cout<<h->arr[i]<<" ";
	}
	cout<<endl;
}

int main(){

	vector<int> arr = {1,2,3,4,5,6,7,8};
	Heap* h = buildHeap(arr);
	disp(h);

	cout<<"Max :"<<getMax(h);
	return 0;
}
