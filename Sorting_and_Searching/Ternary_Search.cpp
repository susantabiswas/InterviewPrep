//ternary search
#include<iostream>
#include<vector>
using namespace std;

//returns the index of the element to find
int ternarySearch(vector<int> arr, int key, int l, int r){
	//we divide the array into three parts
	if(l<=r){
		int mid1 = l + (r - l)/3;
		int mid2 = mid1 + (r - l)/3;

		//now check
		if(arr[mid1] == key)
			return mid1;
		else if(arr[mid2] == key)
			return mid2;
		//if it lies in the 1st part of array
		else if(key < arr[mid1]){
			return ternarySearch(arr,key,l,mid1-1);
		}
		//if it lies in the last part
		else if(key > arr[mid2]){
			return ternarySearch(arr,key,mid2+1,r);
		}
		//if it lies in the middle part
		else
			return ternarySearch(arr,key,mid1+1,mid2-1);
	}
	return -1;
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
	cout << ternarySearch(arr,15,0,arr.size()-1);
	return 0;
}
