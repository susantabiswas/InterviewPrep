//Merge sort implementation
#include<iostream>
#include<vector>
using namespace std;

//for merging the arrays left and right
/*
	For merging we make a temp vector and store the merged vector
*/
void merge(vector<int> &arr,int l,int mid,int r){
	//left vector size
	int n1 = mid-l+1;
	//right vector size
	int n2 = r-(mid+1)+1;
	int n = n1+n2;
	//for storing the sorted vector
	vector<int> temp(n);
	int i=l,j=mid+1,k=0;

	while(i<=mid && j<=r){
		temp[k++]=arr[i]<arr[j]?arr[i++]:arr[j++];
	}

	while(i<=mid)
		temp[k++]=arr[i++];

	while(j<=r)
		temp[k++]=arr[j++];

	for (int i = 0; i < n; ++i)
	{
		arr[l+i]=temp[i];
	}
}

//Merge sort function
/*
	Use divide and conquer and keep diving the vector till we are left with only two
	elements then one by one merge the sorted arrays
*/
void mergeSort(vector<int> &arr,int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main(){

	vector<int> arr={6,1,2,4,55,1,67,3,6,0};

	mergeSort(arr,0,arr.size()-1);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
