//find the maximum element in each of the subarrays of size 'k'
/*
	We scan each window and only allow those elements inside the deque which are
	useful or required.Useful means that element is greater than all the elements 
	on its left.
*/
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxElementSubarray(std::vector<int> &arr, int k){
	//make a deque
	deque<int> d;
	vector<int> res;
	//find the maximum element in the first window
	int i = 0;
	for(; i < k; i++){

		while(!d.empty() && arr[i] >= arr[d.back()])
			d.pop_back();
		d.push_back(i);
	}

	//now the first element is the maximum of the previous window
	for(;i<arr.size();i++){

		res.push_back(arr[d.front()]);

		///now remove the index of elements belonging to the previous window
		while(!d.empty() && d.front()<=i-k)
			d.pop_front();

		//now do the processing for the current window
		while(!d.empty() && arr[i]>= arr[d.back()])
			d.pop_back();
		d.push_back(i);
	}

	res.push_back(arr[d.front()]);
	return res;
}

main(){
	vector<int> arr = {12, 1, 78, 90, 57, 89, 56};
	vector<int> res = maxElementSubarray(arr,3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
