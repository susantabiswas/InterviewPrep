//given an array.Sort it in wave form such that a[0] >= a[1] <=a[2] >= a[3]....
/*
	can be done using:
	1. sort the array and swap the adjacent element after gap of 1
		Tc:O(nlogn)
	2. we are only concerned with the even positions,where the element is supposed
		to be greater than preceding odd and next odd place element
		for all even positions:
		if curr < pred :
			swap(pred,curr)
		if curr < next
			swap(next, curr)
*/
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

//for sorting in wave form
void sortWaveForm(vector<int> &arr){

	for(int i = 0; i<arr.size(); i+=2){

		//when pred odd pos element is greater
		if(i-1>=0 && arr[i-1] > arr[i])
			swap(arr[i-1],arr[i]);
		
		if(i+1<arr.size() && arr[i+1] > arr[i])
			swap(arr[i+1],arr[i]);
	}
}

void disp(vector<int> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	vector<int> arr = {10, 90, 49, 2, 1, 5, 23};
	sortWaveForm(arr);
	disp(arr);
	return 0;
}
