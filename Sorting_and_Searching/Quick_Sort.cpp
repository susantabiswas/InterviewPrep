//quick sort
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

//for partitioning the array
int partition(vector<int> &arr, int l, int h){
	//we select the rightmost as the pivot
	int pivot = arr[h];
	//writable index for smaller elements
	int small = l;
	int i = 0;

	for(i = l; i<= h-1; i++){
		if(arr[i] <= pivot){
			swap(arr[small],arr[i]);
			small++;
		}
	}
	swap(arr[small],arr[h]);
	return small;
}

/*
	for each element from right we find its pivot position and
	place it.We do this for the subparts.
*/
void quickSort(vector<int> &arr, int l, int h){

	if(l<h){
		int p = partition(arr,l,h);

		quickSort(arr,l,p-1);
		quickSort(arr,p+1,h);
	}
}


int main(){
	vector<int> arr = {32,1,4,3,2,5,14};
	quickSort(arr,0,arr.size()-1);
	disp(arr);
	return 0;
}
