// Given a pivot position ,arrange the elements such that on left side elements are lesser
// than pivot element and on right side the elements greater than it
#include<iostream>
#include<vector>
using namespace std;

//position pivot
void positionPivot(vector<int> &arr,int pivot_pos){
	int i = 0;
	int j = arr.size()-1;
	int temp = 0 ;//for swapping
	int pivot = arr[pivot_pos];

	while(i<j){
		//move till the elements are smaller than the pivot element
		while(arr[i] < pivot){
			i++;
		}

		while(arr[j]> pivot){
			--j;
		}

		//swap if possible
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] =temp;
			--j;
		}
	}
	/*temp = arr[j-1];
	arr[j-1] = arr[pivot_pos];
	arr[pivot_pos] = temp;
*/
}

//for displaying the numbers
void disp(vector<int> &arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
}
int main(){
	vector<int> arr = {12,33,14,12411,23,134,443,77};
	cout<<"Pivot:"<<arr[4]<<endl;
	positionPivot(arr,4);

	disp(arr);
	return 0;
}

