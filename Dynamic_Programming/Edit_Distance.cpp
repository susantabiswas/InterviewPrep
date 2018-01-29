//Given two strings str1 and str2.Given three possible operations on str1:
//1)insert char at any pos
//2)remove any char
//3)replace any char
//Find the min cost to convert str1 to str2.
//Cost is same for all 3 operations
#include<iostream>
using namespace std;

//using normal recursion
//Tc: O(3^n)
int editDistance(string a, string b, int m, int n){
	//when string a is smaller it needs 'n' insertions
	if(m == 0)
		return n;
	//when string b is smaller string 'a' requires 'n' deletions
	if(n == 0)
		return m;

	//when both the last chars are same
	if(a[m-1] == b[n-1])
		return editDistance(a, b, m-1, n-1);
	//when they are different,then try all three ops on string 'a' and min of three
	//is the answer
	//insert: m and n-1 :as the nth char was inserted in 'a' so look for the next char in
	//			b
	//delete:m-1 and n: char is removed from 'a' so look in 'a'
	//replace:m-1 and n-1:obvious reasons
	else
		return 1 + min( editDistance(a, b, m, n-1),
					min(editDistance(a, b, m-1, n),
					editDistance(a, b, m-1, n-1))
					);
}

//using DP :tabulation
//TC: O(nm)
int editDistanceDP(string a, string b, int m, int n){
	//create the table
	//op[i][j] represents opeartions required by 'a' with length 'i'
	//to become like 'b' with length 'j'
	int op[m+1][n+1];

	//we start from index 1 because we use [i-1] and [j-1] values
	for(int i = 1; i<=m; i++)
		for(int j = 1; j<=n; j++){
			//it will require j insertions
			if( i == 0 )
				op[i][j] = j;
			//'a' will require 'i' deletions
			if(j == 0)
				op[i][j] = i;
			//when they are same then skip and the required op is same as last
			else if(a[i-1] == b[j-1])
				op[i][j] = op[i-1][j-1];
			//when they are different
			else{
				op[i][j] = 1 + min( op[i][j-1],
								min( op[i-1][j], op[i-1][j-i]) );
			}

		}
	return op[m][n];
}

int main(){
	string a = "sunday";
	string b = "saturday";

	cout<<editDistance(a, b, a.size(), b.size());
	cout<<endl<<editDistanceDP(a, b, a.size(), b.size());
	return 0;
}
