
//Given coins with values v1,v2 ,v3......vn .Now this is a game where we can select
//either a value from front or from back of the coins and we remove it and get to keep
//it.There are even number of coins .Suppose we start first ,then what is the max
//value we can get by playing this game
#include<iostream>
#include<vector>
using namespace std;

#define nil -999999
/*
	Our objective is to get the maximum value and  the opponent wants to
	select a value such that it gives us the min value.
	Also we select a value either from front or back
*/
int maxValue( vector<int> &arr, int i, int j, bool myturn){
	if(i > j)
		return 0;
	//opponent's turn
	if(!myturn)
		return min( maxValue(arr, i+1, j, myturn = true),
					 maxValue(arr, i, j-1, myturn = true));
	//our turn
	else
		return max( arr[i] + maxValue(arr,i+1,j,myturn = false),
					arr[j] + maxValue(arr,i,j-1,myturn = false));
}

//using Dp:Memoization
int maxValueMem( vector<int> &arr, int i, int j, bool myturn, vector< vector<int> >&lookup){
	if(i > j)
		return 0;

	if(lookup[i][j] != nil)
		return lookup[i][j];

	//opponent's turn
	if(!myturn)
		return lookup[i][j] = min( maxValue(arr, i+1, j, myturn = true),
					 maxValue(arr, i, j-1, myturn = true));
	//our turn
	else
		return lookup[i][j] = max( arr[i] + maxValue(arr,i+1,j,myturn = false),
					arr[j] +maxValue(arr,i,j-1,myturn = false));
}
int main(){
	vector<int> arr = {20, 30, 2, 2, 2, 10};
	bool myturn = true;
	cout << maxValue(arr, 0, arr.size()-1, myturn);

	//for dp:entry lookup[i][j] means from coins i to j
	vector< vector<int> > lookup(arr.size(),vector<int>(arr.size(),nil));
	cout << endl << maxValueMem(arr, 0, arr.size()-1, myturn, lookup);
	return 0;
}
