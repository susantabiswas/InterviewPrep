//given two strings ,find the longest common subsequence
//longest common subsequence need not be contigous characters,eg
//ABSDDSDS and ACBXD ,lcs : ABD
#include<iostream>
using namespace std;

//recursive solution
//if L(a[0,m-1],b[0,n-1]) is the length of the LCS ,then it can be found by:
//when their last characters are same:
//	L(a[0,m-1],b[0,n-1]) = 1 + L(a[0,m-2],b[0,n-2])
//when they are different:
//	 L(a[0,m-1],b[0,n-1]) = max( L(a[0,m-2],b[0,n-1]),L(a[0,m-1],b[0,n-2]) )
int findLCS(string a, string b, int m, int n){
	if(m < 0 || n < 0)
		return 0;
	//when their last characters are same
	if(a[m] == b[n])
		return 1 + findLCS(a,b,m-1,n-1);
	else
		return max( findLCS(a,b,m-1,n), findLCS(a,b,m,n-1) );
}

//using DP :tabulation
//Tc: O(nm)
int LCSfindLCSTab(string a, string b, int n, int m){
	//create a table
	int LCS[n + 1][m + 1];
	//here indexing has been taken from 1
	//here index i and j tells about the length of LCS till
	//ith index of a and jth index of b
	for(int i = 0; i<=n; i++)
		for(int j = 0; j<=m; j++){
				if(i == 0 || j == 0)
					LCS[i][j] = 0;

				else if(a[i-1] == b[j-1])
					LCS[i][j] = 1 + LCS[i-1][j-1];
				//when the last chars are not equal then find the max of 
				//LCS with 0..m-1 and 0..n and 0..m and 0..n-1
				else
					LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
		}

	return LCS[n][m];
}

int main(){
	string a = "AGGTAB";
	string b = "GXTXAYB";
	cout << findLCS(a, b, a.size()-1, b.size()-1);
	cout<<endl<<LCSfindLCSTab(a,b,a.size(), b.size());
	return 0;
}
