//gievn an array of numbers .arrange in such a away that all the even nos. comes first and all the odd numbers
//comes in the end
#include<iostream>
#include<vector>
using namespace std;


//arranges the numbers
void arrangeNum(vector<int> &arr){

	int i = 0;		//for keeping track of even nos.
	int j = arr.size();//for keeping track of odd nos.
	int t =0 ;

	while(i<j){
		//when the num is odd swap it with the odd index
		if(arr[i]%2 != 0){
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			j--;
		}
		else{
			//when the num is even
			++i;
		}
	}
}

void disp(vector<int> &arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
}

int main(){
	int x[] ={12,31,1,4,2387,23,4,1,23,2};
	vector<int> arr(x, x+10);
	arrangeNum(arr);
	disp(arr);
	return 0;
}