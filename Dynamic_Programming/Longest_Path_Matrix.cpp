//given a matrix ,find the longest path in the matrix starting from any cell
// such that in the path each next element is increasing by a difference of 1
//All the elements are distinct
/*
	we find the path from each cell and return the maximum path
*/
//TC: O(n^2)
#include<iostream>
#include<vector>
using namespace std;

//returns the path length
int findPath(vector< vector<int> > &mat, int i, int j, int n,vector< vector<int> > &lookup){
	//base condition
	if( i < 0 || i >= n || j<0 || j>=n)
		return 0;

	if(lookup[i][j] != -1)
		return lookup[i][j];

	//since all the values are distinct so only there can be atmost one
	//way to move forward which has diff 1 and is greater
	//we can move in 4 directions:left right up down from any cell
	//or it can't move further

	//left movement
	if( j-1 >=0 && ( mat[i][j] + 1 == mat[i][j-1]) )
		return lookup[i][j] = 1 + findPath(mat, i, j-1, n, lookup);
	//right movement
	if( j+1 < n && (mat[i][j] + 1 == mat[i][j+1]))
		return lookup[i][j] = 1 + findPath(mat, i, j+1, n, lookup);
	//up movement
	if( i-1 >= 0 && (mat[i][j] + 1 == mat[i-1][j]))
		return lookup[i][j] = 1 + findPath(mat, i-1, j, n, lookup);
	//down movement
	if(i+1 <n && (mat[i][j] + 1 == mat[i+1][j]))
		return lookup[i][j] = 1 + findPath(mat, i+1, j, n, lookup);

	//when it can't move further
	return lookup[i][j] = 1;
}

//returns the maximum length of all the paths
int findMaxPath(vector< vector<int> > &mat){
	//n is the col and n is the row
	int n = mat[0].size();
	int curr = 0;
	int max = -1;
	//create a lookup table and init with -1
	vector < vector<int> > lookup( n, vector<int>(n,-1));
	//for each cell find the path
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++){
			curr = findPath(mat, i, j, n, lookup);
			if(curr > max)
				max = curr;
		}
	return max;
}

int main(){
	vector< vector<int> > mat = {{1, 2, 9},
			                    {5, 3, 8},
			                    {4, 6, 7}};
	cout << findMaxPath(mat);
	return 0;
}
