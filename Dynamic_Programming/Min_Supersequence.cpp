//given two strings str1 and str2.Find the shortest supersequence length which contains
//both the strings as sub sequence
/*
	supersequence is basically the intersection of both strings + uncommon chars
	from both str
	find the lcs then:
		length of superseq. = length(str1) + length(str2) - lcs
*/
#include<iostream>
#include<vector>
using namespace std;

//finds the lcs
int findLCSMem(string s1, string s2, int m, int n, vector< vector<int> > &lookup){
	//base case
	if(m <= 0 || n <= 0)
		return 0;

	if(lookup[m][n] != -1)
		return lookup[m][n];

	//when the chars match
	if(s1[m-1] == s2[n-1])
		return lookup[m][n] = 1 + findLCS(s1, s2, m-1, n-1, lookup);
	else
		return lookup[m][n] = max( findLCS(s1, s2, m-1, n, lookup),
								   findLCS(s1, s2, m, n-1, lookup) );
}

//TC:O(nm)
//finds the length of the supersequence 
int minSuperSeq(string s1, string s2, vector< vector<int> > lookup){
	//find the lcs
	int lcs = findLCS(s1,s2,s1.size(),s2.size(),lookup);

	return ( s1.size() + s2.size() - lcs);
}

int main(){
	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";

	//for lca dp
	vector< vector<int> > lookup(str1.size() + 1, vector<int>(str2.size() + 1,-1));
	cout<< minSuperSeq(str1, str2, lookup);
}
