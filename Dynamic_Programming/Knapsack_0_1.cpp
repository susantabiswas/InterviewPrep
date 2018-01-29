//0-1 Knapsack problem
//Given a knapsack of weight 'w' and list of pieces of different weights and their prices
//Find the maximum value that we can get by filling the knapsack with these weights
//It differs from Rod cutting problem in the sense that here each item is not unlimited
//once it is included it gets finished
#include<iostream>
#include<vector>
using namespace std;

#define nil -99999

//finds the max value of knapsack
//now in knapsack ,we can either keep and include a item or exclude it
int maxKnapsackValue( vector<int> &weight, vector<int> &value, int W, int n){
	//when the item list has finished or weight has become zero
	if( W <= 0 || n == 0)
		return 0;

	//if the current item has a weight greater than W
	if(weight[n-1] > W)
		return maxKnapsackValue(weight, value, W, n-1);
	//check for both possibilities :including and excluding the current item
	return max( maxKnapsackValue(weight, value, W, n-1), value[n-1] +
				maxKnapsackValue(weight, value, W - weight[n-1], n-1) );
}

//using Dp: memoization
int maxKnapsackValueMem( vector<int> &weight, vector<int> &value, int W, int n,
								vector< vector<int> > &lookup){
	if(lookup[n][W] != nil)
		return lookup[n][W];

	if(W<=0 || n == 0){
		lookup[n][W] = 0;
		return lookup[n][W];
	}

	if(weight[n-1] > W){
		lookup[n-1][W] = maxKnapsackValueMem(weight, value, W, n-1, lookup);
		return lookup[n-1][W];
	}

	lookup[n][W] = value[n-1] + maxKnapsackValueMem(weight, value, W - weight[n-1], n-1, lookup);

	lookup[n-1][W] = maxKnapsackValueMem(weight, value, W, n-1, lookup);

	return max(lookup[n-1][W] , lookup[n][W]);
}

//using DP:tabulation
//Tc: O(n*W)
int maxKnapsackValueTab(vector<int> &weight, vector<int> &value, int W, int n){
	//keeps track of max value that can be obtained from 'i' items and 'j' weights
	vector< vector<int> > lookup(weight.size() + 1,vector<int>(W+1,0));

	for(int i = 0; i<=n; i++)
		for(int j = 0; j<=W; j++){
				if( i == 0 || j == 0)
					lookup[i][j] = 0;
				else if(weight[i-1] < j)
					lookup[i][j] = lookup[i-1][j];
				else
					lookup[i][j] = max(lookup[i-1][j] , value[i-1] + lookup[i-1][j]- weight[i-1]);
		}
		return lookup[n][W];
}

int main(){
	 vector<int>  value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int  W = 50;

	vector< vector<int> > lookup(weight.size() + 1,vector<int>(W+1,nil));
	cout << maxKnapsackValue(weight, value, W, weight.size());
	cout << endl << maxKnapsackValueMem(weight, value, W, weight.size(), lookup);
	cout<< endl<< maxKnapsackValue(weight, value, W, weight.size());
}
