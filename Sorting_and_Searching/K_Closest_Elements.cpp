//given a sorted array ,find k closest elements to the given key
/*
	find the key using binary search,then start from its left and right
	elements and start comparing which is more closer
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//binary search
int binarySearch(vector<int> &arr, int l, int r, int key){
	int mid = l +(r-l)/2;

	if(arr[mid] == key)
		return mid;
	else if(arr[mid] < key)
		return binarySearch(arr,mid+1,r,key);
	else if(arr[mid]>key)
		return binarySearch(arr,l,mid-1,key);
	return -1;
}

//iterative binary search
int bSearch(vector<int> arr,int l, int r, int key){
	l = 0;
	r = arr.size()-1;
	int mid = l + (r-l)/2;

	while(l>=0 && r<arr.size() && l<r){
		mid = l + (r-l)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

//prints the k closest elements
void printKClosest(vector<int> &arr, int key, int k){
	int pos = bSearch(arr,0,arr.size()-1,key);
	cout<<pos<<endl;
	//now search in left and right of the key
	int l = pos-1;
	int r = pos+1;
	int i = 0;

	while(l>=0 && r<arr.size() && i<k){
		//start checking
		if( (abs(arr[l] - key)) < (abs(arr[r]-key)) ){
			++i;
			cout<<arr[l--]<<" ";
		}
		else{
			++i;
			cout<<arr[r++]<<" ";
		}
	}
	if(i<k){
		while(l>=0 && i<k){
			++i;
			cout<<arr[l--]<<" ";
		}
		while(r<arr.size() && i<k){
			++i;
			cout<<arr[r++]<<" ";
		}
	}
}

int main(){
	vector<int> arr = {12, 16, 22, 30, 35, 39, 42,
               45, 48, 50, 53, 55, 56};
	int key = 35;
	printKClosest(arr,key,4);
	return 0;
}
