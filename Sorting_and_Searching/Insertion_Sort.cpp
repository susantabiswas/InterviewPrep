//insertion sort
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

void insertionSort(vector<int> &arr){
	int j = 0;
	int temp = 0;
	int n = arr.size();

	for(int i = 1; i<n; i++){
		j = i - 1;
		temp = arr[i];
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			--j;
		}
		swap(arr[j+1],temp);
	}
}


int main(){
	vector<int> arr = {32,1,4,3,2,5,14};
	insertionSort(arr);
	disp(arr);
	return 0;
}
