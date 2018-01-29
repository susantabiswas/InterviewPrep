//given an array of +ve moves for a board game ,check whether the 
//moves can make you reach the goal or not
/*
	We keep track of the furthest that we can move and check this till the second last
	position and then see if the furthest move is greater than than the goal that return
	true .
	Now if we get to that position which is the furthest we can move then if from
	that position we cannot move further then return false
*/
#include<iostream>
#include<vector>
using namespace std;

//checks whether the moves can reach the final place in the board game
bool checkMoves( vector<int> &arr){
	int furthest = 0;
	int goal = arr.size() -1;

	//move till the second last position
	for(int i =0 ; i<goal; i++ ){
		if(furthest >= goal)
			return true;
		if(furthest == i){
			if(arr[i] == 0)
				return false;
			furthest += arr[i];
		}
		else{
			if( arr[i] + i > furthest)
				furthest = arr[i] +i;
		}
	}

	if(furthest >= goal)
		return true;
	else
		return false;

}

main(){
	vector< int> arr = {3,3,1,0,2,0,1};
	cout<<checkMoves(arr);
}
