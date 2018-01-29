//given an array.Find the sum of minimum and maximum of all the subarrays of size 'k'
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int findMaxMinSum(std::vector<int> &arr, int k){
	deque<int> d1(k);	//for maximum element
	deque<int> d2(k);	//for minimum element
	int sum = 0;

	//first window
	int i = 0;
	for(; i< k ; i++){

		while(!d1.empty() && arr[i] >= arr[d1.back()])
			d1.pop_back();
		d1.push_back(i);

		while(!d2.empty() && arr[i] < arr[d2.back()])
			d2.pop_back();
		d2.push_back(i);
	}

	//go for the rest of the elements
	for(; i<arr.size(); i++){

		sum += arr[d1.front()] + arr[d2.front()];
		cout<<"max:"<<arr[d1.front()]<<" min:"<<arr[d2.front()]<<endl;
		//remove out of index elements
		while(!d1.empty() && d1.front() <= i-k)
			d1.pop_front();
		while(!d2.empty() && d2.front() <= i-k)
			d2.pop_front();

		//process the current window
		while(!d1.empty() && arr[i] >= arr[d1.back()])
			d1.pop_back();
		d1.push_back(i);

		while(!d2.empty() && arr[i] < arr[d2.back()])
			d2.pop_back();
		d2.push_back(i);
	}

	sum += arr[d1.front()] + arr[d2.front()];
	cout<<"max:"<<arr[d1.front()]<<" min:"<<arr[d2.front()]<<endl;
	return sum;
}

main(){
	vector<int> arr = {2, 5, -1, 7, -3, -1, -2} ;
	cout<<findMaxMinSum(arr,3);
}
