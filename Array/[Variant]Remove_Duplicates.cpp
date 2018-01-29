//given a array with one key which has repeating occurrences .Given that key
//remove all the instances of that key from the array
#include<iostream>
#include<vector>
using namespace std;

template <class T>
void disp(T arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//removes the duplicates of the key
/*
	Every element except the key should exist so whenever we encounter a element key
	then note down its position so that another element can take its place which is not
	the key then we replace it.
	Now after replacing we will have 2 instances of that element ,to remove that we make 
	that element as the key so that the function can take care of it
*/
vector<int> removeDuplicates(vector<int> &arr,int key)
{
	int write = -1;
	for(int i = 0;i< arr.size() ;i++){
		if(write == -1 && arr[i] ==key)
			write = i;
		else if(arr[i] != key && write!= -1){
			arr[write] = arr[i];
			arr[i] =key;
			write++;
		}
	}
	return vector<int> { begin(arr),begin(arr)+write};
}

main(){
	vector<int> arr = {1,2,3,4,5,3,6};
	int key = 3;
	vector<int> res = removeDuplicates(arr,key);
	disp(res);
}
