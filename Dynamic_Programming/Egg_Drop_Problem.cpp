//Given 'n' eggs and 'k' floors,find the min number of attempts/drops to find the floor
// from lowest floor from which if the egg is dropped then it will break.
/*
	If there is only 1 egg and k floors then we need to drop it from the 1st floor
	till the floor from which when dropped it breaks
	If we are given 'n' eggs and 'k' floors then we check for each and every floor
	two cases can arrive for the x floor:
	1. Either the egg will break, so recurse for lower floors :n-1,x-1
	2. The egg doesn't break then we need to look for the k-x floors with n eggs

	Now since for each floor we don't know whether the egg will break or not
	so we have to consider both cases of the floors above and below it.
	Now since we need the worst case so for both of the cases ,we can get the
	worst by taking MAX of both.
	Do this for all k floors and return MIN( all worst cases)
*/
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//finds the critical floor
int findCriticalFloor(int n, int k){
	//when there is no floor left or only one left
	if(k == 0 || k == 1)
		return k;

	//when 1 egg is there
	if( n == 1)
		return k;

	int min = numeric_limits<int>::max();
	int curr = 0;
	//check for each floor
	for (int i = 1; i <=k; ++i)
	{
		//take the worst case:
		//when the egg breaks,fo to lower floors
		//when it doesn't break go to upper floors
		curr = max( findCriticalFloor(n-1, i-1), findCriticalFloor(n, k-i) );
		if( curr < min)
			min = curr;
	}
	//+1 for taking into account for  dropping from the current floor
	return min + 1;
}

//TC:O(nk^2)
//using DP:Memoization
int findCriticalFloorMem(int n, int k, vector< vector<int> > &lookup){
	if(k == 1 || k == 0)
		return k;
	if(lookup[k][n] != -1)
		return lookup[k][n];

	int min = numeric_limits<int>::max();
	int curr = 0;
	//check for each floor
	for (int i = 1; i <=k; ++i)
	{
		//take the worst case:
		//when the egg breaks,fo to lower floors
		//when it doesn't break go to upper floors
		curr = max( findCriticalFloor(n-1, i-1), findCriticalFloor(n, k-i) );
		if( curr < min)
			min = curr;
	}
	//+1 for taking into account for  dropping from the current floor
	return lookup[k][n] = min + 1;
}

main(){
	//floors
	int k = 10;
	//eggs
	int n = 2;
	cout << findCriticalFloor(n, k);

	//for dp:entry lookup[i][j] means the min trials for k floors with j eggs
	vector< vector<int> > lookup( k+1, vector<int>(n+1,-1));
	cout << endl << findCriticalFloorMem(n, k, lookup);
}
