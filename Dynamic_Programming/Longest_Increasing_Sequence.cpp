//given an array,find the longest increasing sequence LIS for it
#include<iostream>
#include<vector>
using namespace std;

#define nil -99999999
//finds the LIS
/*
	we use an array LIS ,where LIS[i] stores the LIS if 'i' is the last element in the
	LIS,so LIS[i] = max(LIS[j]) + 1, where j<i and arr[i] > arr[j]
	So we find this for each element and find the max from it

*/
//returns the LIS of the last element
//max_lis stores the maximum lis
/*
	Here it has overlapping subproblem as every time for checking the previous element
	we have to again recurse and again find previous elements till there
	Optimal Substructure: Finding the max lis for each element is achieved by finding the
	max lis for its previous elements
*/

int findLIS(vector<int> &arr, int n, int &max_lis){
	if(n == 1)
		return 1;

	//lis for this element
	int lis_here = 1;
	int res = 0;
	//now check for the lis of its previous elements which satisfies the conditions
	//mentioned above
	for(int i = 1; i<n; i++){
		//find the lis of 'i'th element
		res = findLIS(arr, i, max_lis);

		//now check
		if( lis_here < res + 1 && arr[i-1] < arr[n-1])
			lis_here = res + 1;
	}

	//now check for the max lis
	if(lis_here > max_lis)
		max_lis = lis_here;
	return lis_here;
}

////same as above but uses DP
////memoization has been used
//lookup for memoization
//TC: O(n^2)
int findLISDPMem(vector<int> &arr, vector<int> &lookup, int n, int &max_lis){
	//when it is the first element
	if(n == 1){
		lookup[n-1] = 1;
		return lookup[n-1];
	}


	int lis_here = 1;

	for(int i = 1; i<n; i++){
		if(lookup[i-1] == nil)
			lookup[i-1] = findLISDPMem(arr,lookup,i,max_lis);
		if(lookup[i-1] + 1 > lis_here && arr[i-1] < arr[n-1])
			lis_here = lookup[i-1] + 1;
	}
	lookup[n-1] = lis_here;

	//check for max
	if(max_lis < lookup[n-1])
		max_lis = lookup[n-1];
	return lookup[n-1];
}

//DP using tabulation
//returns the max lis
int findLISDPTab(vector<int> &arr, int n){
	int max_lis = -99999999;
	//make the lookup vector
	vector<int> lookup(arr.size(),1);

	for(int i = 1; i<n; i++)
		for(int j = 0; j<i; j++){
			if(arr[j] < arr[i] && lookup[j] + 1 > lookup[i])
				lookup[i] = lookup[j] + 1;
		}

	//find the max
	for(int i = 0; i<lookup.size(); i++)
		if(lookup[i] > max_lis)
			max_lis = lookup[i];
	return max_lis;
}

int main(){
	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
	int max_lis = -9999999;

	//init the lookup vector
	vector<int> lookup(arr.size(), nil);
	cout<< findLIS(arr,arr.size(),max_lis);
	max_lis = -99999999;
	cout<< endl<<findLISDPMem(arr,lookup,arr.size(),max_lis);
	cout<< endl<<findLISDPTab(arr,arr.size());
}
