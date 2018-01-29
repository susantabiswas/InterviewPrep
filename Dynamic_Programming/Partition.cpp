//given an array of elements.Find whether the array elements can be divided into two
//groups of same size such that the absolute difference between the two is zero
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define nil -999999
//checks if the partition is possible or not for a given array
//TC:O(2^n)
bool isPartitionPossible( vector<int> &arr, int n, int total, int set_sum){
	if( n == 0){
		if( abs( (total - set_sum) - set_sum) == 0)
			return true;
		else
			return false;
	}

	//we can either include the nth element or exclude it, so try both
	return isPartitionPossible(arr, n-1, total, set_sum) ||
			isPartitionPossible(arr, n-1, total, set_sum + arr[n-1]);
}

//using DP:Memoization
//Tc: O(n^2)
bool isPartitionPossible(vector<int> &arr, int n, int total, int set_sum, vector< vector<int> > &lookup){
	if(lookup[n][set_sum] != nil)
		return lookup[n][set_sum];

	if(n == 0){
		if( abs( (total - set_sum) - set_sum) == 0)
			return true;
		else
			return false;
	}

	return lookup[n][set_sum] = isPartitionPossible(arr, n-1, total, set_sum, lookup) ||
								isPartitionPossible(arr, n-1, total, set_sum + arr[n-1], lookup);
}
int main(){
	vector<int> arr = {3, 1, 5, 9, 1};

	//find the total array sum
	int total = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		total += arr[i];
	}

	//for dp:where each entry lookup[i][j] says whether with 'i' elements we
	//can achieve the sum 'j' or not
	vector< vector<int> > lookup(arr.size() + 1, vector<int>(total + 1,nil));
	int set_sum = 0;
	cout << isPartitionPossible(arr, arr.size(), total, set_sum);
	cout << endl << isPartitionPossible(arr, arr.size(), total, set_sum, lookup);
}
