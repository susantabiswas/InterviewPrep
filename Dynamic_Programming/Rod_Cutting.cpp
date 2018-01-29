//Given a rod of length 'n' inches and a list of different prices for different lengths
//lesser than equal to 'n'.Find the max profit that can be achieved by cutting the rods
//into smaller pieces
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices, int n){
	if(n == 0)
		return 0;
	int max_profit = -999999999;
	int profit = 0;
	//try every profit cmb possible
	for (int i = 0; i < n; ++i)
	{
		profit = prices[i] + maxProfit(prices, n - i - 1);
		if(profit > max_profit)
			max_profit = profit;
	}
	return max_profit;
}

int maxProfit1(vector<int> prices, int n, int inch){
	if(n <= 0 || inch <= 0)
		return 0;
	if(n > inch)
		return maxProfit1(prices, n-1, inch);
	return max( maxProfit1(prices, n-1, inch),
				maxProfit1(prices, n, inch-n) + prices[n-1]
				);
}

//using DP:tabulation
int maxProfitDP(vector<int> prices, int n){
	//stores max profit for ith length
	vector<int> profit(n+1);
	profit[0] = 0;

	int val;
	int max_val = -999999999;
	//for each length we check for all possible lengths lesser than that
	for (int i = 1; i <=n; ++i)
	{
		//for each length lesser than this find the one which maximises
		for(int j = 0; j<i; j++){
			val = prices[j] + profit[ i - j -1];
			if(val > max_val)
				max_val = val;
		}
		profit[i] = max_val;
		max_val = -9999999999;
	}

	return profit[n];
}

int main(){
	vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = prices.size();
	cout<< maxProfit(prices,n);
	cout<< endl << maxProfit1(prices,8,n);
	cout<< endl<< maxProfitDP(prices,n);
}
