//bubble sort implementation
#include<iostream>
#include<vector>
using namespace std;

//bubble sort function
void bubbleSort(vector<int> &arr){
	int temp;
	int n=arr.size();
	
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j <n-1-i; ++j){
			if(arr[j]>arr[j+1]){
				//swap if found bigger
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}		
		}	
	}
}

int main(){

	vector<int> arr={6,1,2,4,55,1,67,3,6,0};

	bubbleSort(arr);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}