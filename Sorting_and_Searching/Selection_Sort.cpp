//selection sort
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
/*
	our aim is to do a traversal and in each traversal we find the max element
	and swap it with the last element.In next traversal we end at one element before
	the last and so on.
*/
void selectionSort(vector<int> &arr){
	int n = arr.size();
	int max = 0;
	for(int i = 0; i<n-1; i++){
		max = 0;
		for(int j = 0; j < n - i ; j++){
			if(arr[j] > arr[max])
				max = j;
		}
		swap(arr[n-i-1],arr[max]);
	}
}


int main(){
	vector<int> arr = {32,1,4,3,2,5,14};
	selectionSort(arr);
	disp(arr);
	return 0;
}
