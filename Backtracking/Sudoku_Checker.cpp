//Given a 9 x 9 Sudoku ,which is partially filled .
//Fill the sudoku ,digits allowed are 1-9
//A number is allowed only once in its row and col and also 
//in the smaller grid of 3 x 3
#include<iostream>
#include<vector>
using namespace std;

//checks if a number can be assigned for a place in the sudoku board
bool isSafe(vector<vector <int> > &arr, int num, int row, int col){

	//check in the row
	for (int i = 0; i < arr[0].size(); ++i)
	{
		if(arr[i][col] == num)
			return false;
	}

	//check in the column
	for(int i = 0; i<arr[0].size(); i++)
		if(arr[row][i] == num)
			return false;

	//check in the 3 x 3 grid
	int grid_i = (row/3 )*3;
	int grid_j = (col/3)*3;
	for(int i = grid_i; i<(grid_i + 3); i++)
		for(int j = grid_j; j<(grid_j + 3); j++){
			if(arr[i][j] == num)
				return false;
		}
	return true;
}

//finds unassigned position in the matrix and returns true if found 
//else false is returned
bool giveUnassigned(vector< vector <int> > arr, int &row, int &col){
	for(int i = 0; i<arr[0].size(); i++)
		for(int j = 0; j<arr[0].size(); j++)
			if(arr[i][j] == 0){
				row = i;
				col = j;
				return true;
			}
	return false;
}

bool fillSudoku(vector<vector <int> > &arr, int row, int col){
	//when all the numbers have been assigned
	if(!giveUnassigned(arr, row, col))
		return true;

	//check with the numbers 1-9
	for (int num = 1; num <= 9; ++num){
		if(isSafe(arr, num, row, col)){
			arr[row][col] = num;
			if(fillSudoku(arr, row, col))
				return true;
			else
				arr[row][col] = 0;
		}
	}
	return false;
}

//prints sudoku
void printSudoku(vector< vector<int> > arr ){
	for(int i = 0; i<arr[0].size(); i++){
		for(int j = 0; j<arr[0].size(); j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}

}

int main(){
	vector< vector<int> > arr = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
			                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
			                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
			                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
			                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
			                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
			                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
			                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
			                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	int i = 0, j = 0;
	if(fillSudoku(arr,i,j))
		printSudoku(arr);
	else
		cout<<"No solution found";
}
