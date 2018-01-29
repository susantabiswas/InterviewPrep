//Knight Tour problem
//Here we find whether there exist any sequence of moves such that all 
//the squares are visited exactly once.A knight can have max 8 
//possible moves
//Tc : 8^(n^2 - 1)
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
bool isValidMove(vector< vector<int> > &sol, int x_coor, int y_coor){
	//move is valid when its position is inside the chess board and
	//leads to a vacant cell
	return (x_coor < sol[0].size() && x_coor >= 0
			&& y_coor < sol[0].size() && y_coor >= 0
			&& sol[x_coor][y_coor] == -1);
}

//for each current position it tries all the possible moves which 
//are valid and if any of the valid move path is succesfull 
//returns true shows only one of the many possible paths
bool findKnightTour(int cur_x, int cur_y,
					vector< vector<int> > &sol,
					vector<int> &xCoor,
					vector<int> &yCoor, int moveNum){

	//when the current move is the last move
	if(moveNum == sol[0].size()*sol[0].size())
		return true;

	//current moves for trial
	int x_move ;
	int y_move ;
	//check for possible valid moves
	for (int i = 0; i < 8; ++i)
	{
		x_move = cur_x + xCoor[i];
		y_move = cur_y + yCoor[i];

		//check if the current move is valid or not
		if(isValidMove(sol,x_move, y_move)){
			//update the current cell's move number
			sol[x_move][y_move] = moveNum;
			//recurse for further cells
			if(findKnightTour(x_move, y_move, sol, xCoor, yCoor, moveNum + 1))
				return true;
			else{
				//if there is no path with this move then revert back
				//the cell's move num
				sol[x_move][y_move] = -1;
			}
		}
	}
	return false;
}

//driver function
void findKnightTourDriver(){
	//create a 2d solution matrix with each place denoting  a 
	//place in the chess board
	vector< vector<int> > sol(8,vector<int>(8,-1));

	//for storing the x and y coordinates of the possible moves
	//inti moves for starting from (0,0)
	vector<int> xCoor = {1,2,2,1,-1,-2,-2,-1};
	vector<int> yCoor = {2,1,-1,-2,-2,-1,1,2};

	//for keeping track of the current move
	int moveNum = 0;

	//since we start from first end so number it 0
	sol[0][0] = 0;
	moveNum = 1;
	//finds recursively whether there exist any path or not
	//if there is a path then it returns true else false

	int cur_x = 0;
	int cur_y = 0;
	if(findKnightTour(cur_x,cur_y,sol,xCoor,yCoor,moveNum))
		printSolution(sol);
	else
		cout<<"No solution possible \n";
}

int main(){
	findKnightTourDriver();
}
