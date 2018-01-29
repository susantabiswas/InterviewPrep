//merge sort
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

void disp(vector<int> arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//for merging two sorted arrays
void merge(vector<int> &arr,int l, int mid, int r){
	int i = 0;
	int j = 0 ;
	int in = l;
	int n = mid - l + 1;
	int m = r - mid;

	//for storing the 1st array
	vector<int> a(n);
	//for storing the 2nd array elements
	vector<int> b(m);

	//copy the elements
	for (int i = l,j = 0; i <=mid; ++i,++j)
	{
		a[j] = arr[i];
	}
	//copy the elements
	for (int i = mid + 1,j = 0; i <=r; ++i,++j)
	{
		b[j] = arr[i];
	}

	while( i<a.size() && j<b.size()){
		if(a[i]<b[j]){
			arr[in++] = a[i++];
		}
		else{
			arr[in++] = b[j++];
		}
	}

	if(i<a.size()){
		arr[in++] = a[i++];
	}
	if(j<b.size())
		arr[in++] = b[j++];
}

/*
	we keep on splitting the array and then when we have two elements then
	we sort it and return it.Then we merge the sorted arrays and finally
	keep on merging the sorted arrays
*/
void mergeSort(vector<int> &arr, int l, int r){

	if(l<r){
		//for overflow handling
		int mid = l +(r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}


int main(){
	vector<int> arr = {32,1,4,3,2,5,14};
	mergeSort(arr,0,arr.size()-1);
	disp(arr);
	return 0;
}
