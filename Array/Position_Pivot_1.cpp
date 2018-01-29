// Given a pivot position ,arrange the elements such that on left side elements are lesser
// than pivot element and on right side the elements greater than it
#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//for displaying the numbers
void disp(vector<int> &arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//position pivot
void positionPivot(vector<int> &arr,int pivot_pos){
	//we can have three groups :
	/*
		small -1: <x
		small - (equal-1) : ==x
		top :>x
		equal - (top-1):unclassified
		if group them accordingly
	*/
	int smallp = 0 ;
	int equalp = 0;
	int largep = arr.size() ;
	int pivot = arr[pivot_pos];

	while( equalp < largep){

		if(arr[equalp] < pivot){
			//move it to the smaller region
			swap(arr,smallp++,equalp++);
			//smallp++;
		}
		else if(arr[equalp] > pivot){
			//move it to larger region
			swap(arr,--largep,equalp);
			//--largep;
		}
		else{
			equalp++;
		}

	}

}


int main(){
	vector<int> arr = {12,33,14,12411,23,134,443,77};
	cout<<"Pivot:"<<arr[4]<<endl;
	positionPivot(arr,4);

	disp(arr);
	return 0;
}

