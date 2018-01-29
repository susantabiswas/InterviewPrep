///Given an array and a 'k'.Find the subset of the array elements 
//whose sum is equal to k
//TC:2^arr.size
/*
By sorting the data we can improve its performance
*/
#include<iostream>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;

//finds the sumset sum if equal to k
bool findSubsetSum(deque<int> &sol, vector<int> &arr, int l,
					 int r, int sum, int k){
	if(sum == k)
		return true;
	//if we don't sort the array then we can't decide if this path can lead to
	//solution or not,because in unsorted data there might be some negative
	//element after this element also that can make the sum equal to k
	//but once the data is sorted we can guarantee that the if the sum has become
	//greater than k then the next elements will only increase the sum further
	if(sum > k)
		return false;
	for(int i = l; i<=r; i++){
		sol.push_back(arr[i]);
		if(findSubsetSum(sol, arr, i+1,r, sum+arr[i],k))
			return true;
		else
			sol.pop_back();
	}
	return false;
}

//driver function for the subset sum
void findSubsetSumDriver(vector<int> &arr, int k){
	//make a solution vector for storing the subset elements
	deque<int> sol;
	//for keeping track of current sum
	int sum = 0;
	//for keeping track of the lower and upper index of array
	int l = 0;
	int r = arr.size()-1;

	//sort the array for pruning in the tree
	sort(arr.begin(),arr.end());
	if(findSubsetSum(sol, arr, l, r, sum, k)){
		deque<int>::iterator it;
		for(it = sol.begin(); it!= sol.end(); it++)
			cout<<*it<<" ";
	}
	else
		cout<<"No subset can be found !";

}

int main(){
	int k = 47;
	vector<int> arr = {10, 7, 5, 18, 12, 20, 15};
	findSubsetSumDriver(arr,k);
}
