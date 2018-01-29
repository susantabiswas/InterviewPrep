//Given a vector which represents the dimensions of different matrices.Find
//the order in which there will be minimum number of multiplications involved
//vector for ith matrix:order[i-1] :row and order[i]:col
#include<iostream>
#include<vector>
using namespace std;

#define nil -9999999

//finds the min operations required for chain multiplication of matrix
int minOperation(vector<int> &order, int i, int j){
	//when  single matrix is pitted against itself only
	if( i == j )
		return 0;
	//for keeping count of min operation count
	int min_count = 9999999;
	//for keeping track of operation count for current cmb
	int count = 0;
	//try putting parenthesis in all n-1 positions
	//once we put a set of parenthesis then that again becomes a subproblem
	//to solve and the other pair also becomes another subproblem.Now these
	//two should also be multiplied so,for that we multiply the row of first
	//resultant matrix with the col common in those two parenthesis and the col
	//of the second parenthesis
	//in general: (n x m) x ( m x p) = n x p
	for (int k = i; k < j; ++k)
	{
		count = minOperation(order, i, k) +
				minOperation(order,k+1,j) +
				order[i-1]*order[k]*order[j];

		if (count < min_count)
			min_count = count;
	}
	return min_count;
}

//using DP:memoization
int minOperationMem(vector<int> &order, int i, int j, vector< vector<int> > &lookup){
	if(i == j){
		lookup[i][j] = 0;
		return lookup[i][j];
	}

	int min_count = 999999;
	int count = 0;
	for(int k = i; k<j; k++){
		if(lookup[i][k] == nil){
			lookup[i][k] = minOperationMem(order, i, k, lookup);
		}
		if(lookup[k+1][j] == nil){
				lookup[k+1][j] = minOperationMem(order, k+1, j, lookup);
		}
		count = lookup[i][k] + lookup[k+1][j] + order[i-1]*order[k]*order[j];
		if(count < min_count)
			min_count = count;
	}
	return min_count;
}

//using DP:tabulation
//	NOTE: DOESN'T WORK
int minOperation(vector<int> &order){
	int n = order.size();
	//for storing the min operations for the matrix starting from i to j
	vector< vector<int> >dp(n+1 vector<int>(n+1));

	int min_count = 9999999;
	int count = 0;

	//when the matrix is multiplied with itself then op = 0
	for(int i = 0; i<n; i++)
		dp[i][i] = 0;

	//for each size find the min operations required
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++){

		}
	return dp[n];
}

int main(){
	vector<int>order = {1, 2, 3, 4, 3};
	//i and j are indices of the columns of the first and last matrices resp.
	int i = 1, j = 3;
	//i and j represents the col of first and last matrix respectively
	cout<< minOperation(order,i,j);
	cout<< endl<< minOperation(order);

	vector< vector<int> > lookup(order.size() + 1, vector<int>(order.size() + 1,nil));
	cout<< endl<< minOperationMem(order,1,3,lookup);
}
