//selection sort implementation
#include<iostream>
#include<vector>
using namespace std;

//selection sort function
/*
	Find the smallest element and swap it with the current element starting at position 0
	NOTE:remember updating the el var with the index of current smallest element found so far
*/
void selectionSort(vector<int> &arr){
	int temp;
	int el;
	int n=arr.size();

	for (int i = 0; i <n-1; ++i)
	{
		el=i;
		for (int j = i+1; j <n; ++j){
				if(arr[j]<arr[el]){
					el=j;
				}
		}

		//swap elements
		temp=arr[el];
		arr[el]=arr[i];
		arr[i]=temp;
	}
}

int main(){

	vector<int> arr={6,1,2,4,55,1,67,3,6,0};

	selectionSort(arr);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
