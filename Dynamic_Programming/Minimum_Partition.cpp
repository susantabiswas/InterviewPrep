//given an array .Find the minimum abs difference from the sum of two sets with n and m 
//elements,where n and m can be anything >=0 and <= arr size
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//using recursion
/*
	each element can be either in set1 or set2 .So we find the total sum
	and another setSum which contains the sum for set1 ,then try all cmbs
	and find the least value
*/
int minPartition(vector<int> &arr, int n, int total_sum, int set_sum){
	//when one set is complete
	if(n == 0)
		return abs( (total_sum - set_sum) - set_sum );

	//each element can either be in set1 or set 2,so try both
	return min( minPartition(arr, n-1, total_sum, set_sum + arr[n-1]),
				minPartition(arr, n-1, total_sum , set_sum) );
}

//using DP:tabulation
/*
	create a table dp[n+1][sum+1] where sum is the total sum of all the elements
	,n is the number of elements.Each entry dp[i][j] represents whether any sumbset of those
	i elements can have a sum equal to j or not
*/

int minPartitionDP(vector<int> &arr){
	int n = arr.size();
	int sum = 0;
	//calculate the sum
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	//create a table
	//it is true when subset i can have a sum equal to j
	vector< vector<bool> > dp(n+1 , vector<bool>(sum+1));

	//only the first
	//all elements can have sum 0
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = true;
	}

	//when n = 0 no sum can be achieved
	for (int i = 1; i <= sum; ++i)
	{
		dp[0][i] = false;
	}

	//now give values
	for(int i = 1; i<=n ; i++)
		for(int j = 1; j<= sum; j++){

			//when we don't include ith term then its value is the previous term's value
			dp[i][j] = dp[i-1][j];

			//now to see if the current ith term when included can actually achieve sum j
			if(arr[i-1] <= j){
				//if the previous could have achieved j then its true
				//else see that whether current arr[i-1] is enough to meet j when added
				//with previous terms
				dp[i][j] = dp[i][j] | dp[i-1][j - arr[i-1]];
			}

		}
		int min_val = 99999999;
	//now we need a j which is as close as possible to sum/2
	//now that we have total 'n' elements check for the sum closest to sum/2
	for (int i = 0; i <=sum/2; ++i)
	{
		if(dp[n][i]){
			if(sum-2*i < min_val)
				min_val = sum-2*i;
		}
	}
	return min_val;
}

int main(){
	vector<int> arr = {3, 1, 4, 2, 2, 1};
	int total_sum = 0;

	//find the total sum
	for (int i = 0; i < arr.size(); ++i)
	{
		total_sum += arr[i];
	}
	//sum for set1
	int set_sum = 0;
	int n = arr.size();
	cout<< minPartition(arr, n, total_sum, set_sum);
	cout<<endl<<minPartitionDP(arr);
}
