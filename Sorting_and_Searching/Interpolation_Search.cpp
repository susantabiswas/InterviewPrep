//Interpolation search for array
//Useful only when the array is uniformly distributed wit unique values
/*
	the idea is to use the formula which takes us to the the position closer to the
	index of the key rather than always splitting the array into equal parts
	like in binary search.
	best case: O(loglogn)
	worst case: O(n)

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int interpolationSearch(vector<int> &arr, int l, int h, int key){
	int p ;
	while(arr[l] <= key && l<=h && key <= arr[h]){
		p = l + ((h-l)/(arr[h] - arr[l])) * (key - arr[l]);

		if(arr[p] == key)
			return p;
		else if(arr[p] < key)
			l = p+1;
		else
			h = p-1;
	}
	return -1;
}

int main(){
	vector<int> arr = {1,6,3,11,9,67,2,90};
	sort(arr.begin(),arr.end());
	cout<<interpolationSearch(arr,0,arr.size()-1,3);
}
