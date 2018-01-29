//N Queen problem
//given n queen we have to place those queens in a N X N chessboard
//making sure that now two queens can attack each other
//TC : T(n) = n*T(n-1) + O(n)
//= O(n!)
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//for printing the matrix
void printSolution(vector< vector<int> > sol){
	for(int i = 0; i<sol[0].size(); i++){
		for(int j = 0; j<sol[0].size(); j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}

//checks if the position for the queen is valid or not
//queen can attack in all directions
bool isValidPosition(vector< vector<int> > &sol, int row, int col){
	int n = sol[0].size();
	//check in the column
	for (int i = 0; i < n; ++i)
	{
		if(sol[i][col] == 1)
			return false;
	}

	int i,j;
	//diagonal checking
	//upwards left
	for(i = row,j = col; i>=0 && j>=0; j--,i--)
		if(sol[i][j] == 1)
			return false;
	//downwards right
	for(i = row,j = col; i<n && j<n; j++,i++)
		if(sol[i][j] == 1)
			return false;
	//upwards right
	for(i = row,j = col; i>=0 && j<n; j++,i--)
		if(sol[i][j] == 1)
			return false;
	//downwards left
	for(i = row,j = col; i<n && j>=0; j--,i++)
		if(sol[i][j] == 1)
			return false;

	return true;
}

//for placing the N queens
bool placeNQueens(vector< vector<int> > &sol, int queens, int row){
	if(queens == 0)
		return true;
	//we check for a col for the queen to place in for a fixed row
	//and each time increase the row index
	for (int j = 0; j < sol[0].size(); ++j){
		if(isValidPosition(sol,row,j)){
			//	cout<<"valid "<<row<<" "<<j<<endl;
				sol[row][j] = 1;
				if(placeNQueens(sol,queens-1,row+1))
					return true;
				else
					sol[row][j] = 0;
			}
	}

	return false;
}

//driver function for N queens
void placeNQueensDriver(int n){
	//create a NxN 2d matrix and initialise with 0
	vector< vector<int> > sol(n, vector<int>(n,0));

	//for keeping count of queens placed
	int queens = n;
	//starting index for the matrix
	int l = 0;

	if(placeNQueens(sol,queens,l))
		printSolution(sol);
	else
		cout<<"Queens can't be placed";
}

int main(){
	int n = 4;
	placeNQueensDriver(n);
}
