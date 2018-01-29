//NOTE: DOESN'T WORK

//given an array of +ve moves for a board game ,give min no. of steps required for achieving
// the goal
/*
	Just like the other variant of the problem ,here we count when the instances when we
	update the furthest value
*/
#include<iostream>
#include<vector>
using namespace std;

//checks whether the moves can reach the final place in the board game
int checkMoves( vector<int> &arr){
	int furthest = 0;
	bool reachibility = false;
	int goal = arr.size() -1;
	int steps = 0;

	//move till the second last position
	for(int i =0 ; i<goal; i++ ){
		if(furthest >= goal){
			reachibility = true;
			break;
		}
		if(furthest == i){
			if(arr[i] == 0){
				break;
			}
			furthest += arr[i];
			steps++;
		}
		else{
			if( arr[i] + i > furthest){
				furthest = arr[i] +i;
				steps++;
			}
		}
	}

	if(reachibility)
		return steps;
	else
		return -1;

}

main(){
	vector< int> arr = {3,1,2,4,2,0,1};
	cout<<checkMoves(arr);
}
