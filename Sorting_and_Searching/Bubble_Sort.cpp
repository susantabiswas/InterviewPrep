//bubble sort
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

void bubbleSort(vector<int> &arr){
	int n = arr.size();

	for(int i = 0; i<n-1; i++)
		for(int j = i; j < n - i - 1; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
}


int main(){
	vector<int> arr = {32,1,4,3,2,5,14};
	bubbleSort(arr);
	disp(arr);
	return 0;
}
