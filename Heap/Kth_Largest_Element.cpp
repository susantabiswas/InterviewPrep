//given an array of elements ,find the kth largest element
/*
	can be done using sliding window : O(k*(n-k)):
	we take a window of size 'k' and assume that the first k elements
	are biggest of all the elements and find the min of those k elements.
	our target is to get the top k largest elements, so for doing that
	we find the min of the k largest in that window and traverse
	the ramaining elements,if any element is greater than the min
	then we remove min and place that element and again find the
	min element in the window
	now if an element deserves a place in the top k elements then it must be
	greater than the min of k window,so after the complete tarversal we will
	be having top k elements and their min will be the kth largest.

	using max heap :O(n) + O(klog(n))

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//finds index of the min element
int findMinIndex(vector<int> arr){
	int in = 0;
	for(int i = 1;i<arr.size();i++){
		if(arr[i] < arr[in])
			in = i;
	}
	return in;
}

void disp(vector<int> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//finds the kth largest number
int findKthLargestNumber(vector<int> &arr, int k){
	//temporary array for storing the top k elements
	//and store the first k elements in it first
	vector<int> temp(arr.begin(),arr.begin() + k);
    int min_index = -1;
	min_index = findMinIndex(temp);


   //now traverse the rest of the elements
   for(int i = k; i<arr.size(); i++){
		if(arr[i] > temp[min_index]){
				temp[min_index] = arr[i];
				min_index = findMinIndex(temp);

		}
   }
   return temp[min_index];
}

int main(){
	vector<int> arr = {2,312,3,12,89,1,5,36};
	cout<< findKthLargestNumber(arr, 3);
	return 0;
}
