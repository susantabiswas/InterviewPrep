//there is a rat in a maze.The maze is represented by a 2d matrix 
//with 1 and 0s .
//1 means  it is possible to go there ,0 means it can't be reached.Find
// whether there is any path for the rat inside for reaching its 
//destination.
//The rat can only move forward and down
//The starting point is the upper left most cell and destination in 
//rightmost cell in the lowest row(bottom most right cell)

/*
	We use backtracing just like the knight problem
*/
#include<iostream>
#include<vector>
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

//for checking if the move is valid or not
bool isValidMove(int move_x, int move_y,
				 vector< vector<int> > &sol,
				 vector< vector<int> > &maze){

	return (move_x >= 0 && move_x < sol.size() && move_y >= 0 && move_y < sol.size()
			&& sol[move_x][move_y] == 0
			&& maze[move_x][move_y] == 1);
}

//for finding if there is any path inside the maze for the rat to reach its dest or not
bool findMazePath(int curr_x, int curr_y, vector< vector<int> > &sol,
					vector<int> x_coor, vector<int> y_coor, int n,
					vector< vector<int> > &maze){
	//check if the dest is reached or not,
	//assuming the dest is always 1
	if(curr_x == n-1 && curr_y == n-1){
		sol[n-1][n-1] = 1;
		return true;
	}

	int x_move ;
	int y_move ;
	//it has two possible moves
	for (int i = 0; i < 2; ++i)
	{
		x_move = curr_x + x_coor[i];
		y_move = curr_y + y_coor[i];

		if(isValidMove(x_move, y_move, sol, maze)){
			sol[curr_x][curr_y] = 1;
			if(findMazePath(x_move, y_move, sol, x_coor, y_coor, n, maze))
				return true;
			else
				sol[curr_x][curr_y] = 0;
		}
	}
	return false;
}

//driver function for finding the path inside the maze
void findMazePathDriver(vector< vector<int> > maze){

	//sol contains the path for the rat to escape the maze
	vector < vector<int> > sol(maze[0].size(), vector<int>(maze[0].size(),0));

	//valid set of moves ,rat can move forward and down only
	vector<int> x_coor = {0,1};
	vector<int> y_coor = {1,0};

	//mark the starting
	sol[0][0] = 1;
	int curr_x = 0;
	int curr_y = 0;

	//for finding the dest index
	int n = maze[0].size();
	if(findMazePath(curr_x, curr_y, sol, x_coor, y_coor, n, maze))
		printSolution(sol);
	else
		cout<<"No path is possible !";
}

int main(){
	vector< vector<int> > maze = {  {1, 0, 0, 0},
							        {1, 1, 0, 1},
							        {0, 1, 0, 0},
							        {1, 1, 1, 1}
							    };
	findMazePathDriver(maze);
}
