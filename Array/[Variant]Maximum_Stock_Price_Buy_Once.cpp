//Given an array of numbers .Find the maximum length of subarray of equal elements
#include<iostream>
#include<vector>
using namespace std;

//gives the maximum length of subarray
int findMaxLength(vector<int> &arr){
	int max_length = 0;
	int curr_length = 0;

	for(int i =1;i<arr.size();i++){

		if(arr[i-1] == arr[i])
			curr_length++;
		else
			curr_length = 0;

		if((curr_length + 1) > max_length)
			max_length = curr_length;

	}
	return max_length;
}

main(){
	vector<int> arr = {1,1,1,22,2,3,3,3,3,4,1,5,4,5,4,7,4};
	cout<< findMaxLength(arr);
}
