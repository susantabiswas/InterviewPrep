//Given an array with boolean values.Move the false keys to the front and the true keys to the the back
//making sure that the relative ordering of true keys doesn;t change

#include<iostream>
#include<vector>
using namespace std;

//for swapping
template <class T>
void swap(T &arr,int i,int j){
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

//for displaying  the vector
template <class T>
void disp(T &arr){
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//for positioning the boolean keys
void moveKeys(vector<bool> &arr){
	int i = 0 ;
	int j = arr.size() - 1;

	while(i < j){
		if(arr[i] == true){
			swap(arr,i,j--);
		}
		else
			++i;
	}
}

main(){
	vector<bool> arr = {true,false,true,true,false,true,false};
	moveKeys(arr);
	disp(arr);
}
