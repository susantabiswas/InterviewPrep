//given a distance 'd'.Find in how many ways can we cover that distance using only
//1,2 and 3 steps. for distance = 4
//1+3 != 3+1 steps,so unlike coin change problem this can't be done that way
#include<iostream>
#include<vector>
using namespace std;

#define nil -99999
//finds the number of ways of covering the 'd' distance
//TC:O(3^n)
int findWaysToCover( int d){
	if(d == 0)
		return 1;
	if(d < 0)
		return 0;
	return ( findWaysToCover(d-1) + findWaysToCover(d-2) + findWaysToCover(d-3));
}

//using DP:Memoization

int findWaysToCoverMem(int d, vector<int> &lookup){
	if(lookup[d] != nil)
		return lookup[d];
	if(d == 0)
		return 1;
	if(d < 0)
		return 0;

	lookup[d] =  ( findWaysToCover(d-1) + findWaysToCover(d-2) + findWaysToCover(d-3));
	return lookup[d];
}

int main(){
	int d = 4;
	vector<int> lookup(d+1,nil);
	cout << findWaysToCoverMem(d,lookup);
	return 0;
}
