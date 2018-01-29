//given an array which is k sorted that means all the elements are atmost 'k'
//distance far from where they should be if they would have been sorted
//sort the array
/*
	using heap:
		take first 'k' elements and then heapify it
		now for i = k to n-1 :
			pop min from heap and insert arr[i] into heap
			do this for the rest of the elements
	This works beacause an element is atmost 'k' distance far from its correct pos
	so if we take 'k' elements then we are sure to get its correct by having the nearby
	'k' elements
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//comparator for priority queue
struct comp{
	bool operator()(const int&a ,const int&b){
		return a>b;
	}
};

//sorts the array
void kSortArray(vector<int> &arr, int k = 3){
	int i = 0, j = 0;
	int n = arr.size();
	//create a min priority queue
	priority_queue<int, vector<int>, comp> pq;

	//insert the first k elements
	for(; i<k; i++)
		pq.push(arr[i]);

	//now for the rest of the elements
	for(j = 0; i<n && j<n; i++,j++){
		arr[j] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while(!pq.empty()){
		arr[j++] = pq.top();
		pq.pop();
	}
}

int main(){
	vector<int> arr = {2, 6, 3, 12, 56, 8};
	kSortArray(arr,3);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
