//given N as a value and a list of coins with denomination lesser than N
//S1,S2..Sm. In how many ways can we have change for N
#include<iostream>
#include<vector>
using namespace std;

#define nil -99999

//using recursion
/*
	for subproblem with denomination till m, we can either include m or exclude it
*/
int waysToChange(vector<int> &coins, int m, int val){
	//when the total change has been found
	if(val == 0)
		return 1;
	if(val < 0)
		return 0;
	//if mth denomination is zero and value is still remaining
	if(val>=1 && m == 0)
		return 0;
	//when the current denomination is bigger
	if(coins[m-1] > val)
		return waysToChange(coins, m-1, val);
	return waysToChange(coins, m, val - coins[m-1]) + waysToChange(coins, m-1, val);

}

//using DP:Memoization
int waysToChangeMem(vector<int> &coins, int m, int val, vector < vector<int> > lookup){
	if(lookup[m][val] != nil)
		return lookup[m][val];

	if(val == 0){
		//lookup[m][val] = 1;
		return 1;
	}
	if(val < 0){
		return 0;
	}

	if(val>=1 && m == 0){
		//lookup[m][val] = 0;
		return 0;
	}

	if(coins[m-1] > val)
		return lookup[m][val] = waysToChange(coins, m-1, val);

	lookup[m][val] = waysToChangeMem(coins, m, val - coins[m-1], lookup)
					+ waysToChangeMem(coins, m-1, val, lookup);
	return lookup[m][val];
}


//using Dp:Tabulation
int waysToChangeTab(vector<int> &coins, int val){
	//entry dp[i][j] stores the ways in which change can be made for j with denominations array
	//of length i
	vector< vector<int> > dp(coins.size() + 1, vector<int>(val + 1));

	for(int i = 0; i<=coins.size(); i++)
		for(int j = 0; j<=val; j++){

		}
}

int main(){
	vector<int> coins = {1, 2, 3};
	int val = 4;

	//create a lookup table
	vector < vector<int> > lookup( coins.size()+1,vector<int>(val+1,nil));
	cout<< waysToChange(coins, coins.size(), val);
	cout << endl <<waysToChangeMem(coins, coins.size(), val, lookup);
}
