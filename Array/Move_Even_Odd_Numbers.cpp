//given an array.Arrange the elements st even nos. are at the begining and
//the odd nos. are the end
#include<iostream>
#include<vector>
using namespace std;

//moves the even and odd nums
void moveEvenOddNums(vector<int> &arr){
	int i = 0;		//this is for keeping track of even numbers
	int j = arr.size()-1;		//for keeping track of odd numbers
	int temp = 0 ;//for swapping

	while(i<j){
		//when the num. is odd,move it to the odd number position
		if(arr[i]%2 != 0){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			--j;
		}
		else
			++i;
	}
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
	moveEvenOddNums(arr);
	disp(arr);
	return 0;
}
