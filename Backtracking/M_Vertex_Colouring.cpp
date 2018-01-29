//Given a graph and 'm' which denotes the number of unique colours.
//Find whether the vertices of the graph can be coloured such that
// no two vertices get the same colour
//TC :O(v*(v^m)) as color loop is executed v time  so m^v and in 
//worst case  all vertices might get tried
#include<iostream>
#include<vector>
using namespace std;

//for checking if a colour can be assigned to the current node
bool isSafe(vector<int> v, vector< vector<bool> > &graph, int curr_v, int color){
	//if it is already coloured
	if(v[curr_v] != -1)
		return false;
	//just check the colour of its adjacent vetices
	for(int i = 0;i<graph[0].size();i++){
		if(graph[curr_v][i] != -1)
			if(v[graph[curr_v][i] ]== color)
				return false;
	}
	return true;
}
//used for backtracking
bool isColouringPossible( vector< vector<bool> > &graph, int m,
						vector<int> &v, int curr_v){
	if(curr_v >= graph[0].size())
		return true;

	//try for different 'm' colours
	for (int i = 0; i < m; ++i)
	{
		if(isSafe(v,graph,curr_v,i)){
			//assign it the colour if that is possible
			v[curr_v] = i;
			if(isColouringPossible(graph,m,v,curr_v + 1))
				return true;
			else
				v[curr_v] = -1;
		}
	}
	return false;
}

//driver for checking if colouring is possible with 'm' colours or not
void isColouringPossibleDriver(vector< vector<bool> > &graph, int m){

	//create a array representing the different colours used by that vertex
	//where -1 represents no colour has been applied, and i represents the colour used
	vector< int > v( graph[0].size(), -1);

	//keeps track of current vertex
	int curr_v = 0;
	if(isColouringPossible(graph, m, v, curr_v))
		cout<<"Yes";
	else
		cout<<"No";
}

int main(){
	/* Create following graph and test whether it is 3 colorable
      (0)---(2)
       |   / |
       |  /  |
       | /   |
      (3)---(1)
    */
    vector< vector<bool> > graph = {{0, 0, 1, 1},
				        {1, 0, 1, 3},
				        {1, 1, 0, 1},
				        {1, 1, 1, 0},
    				};

    int m = 2;
    isColouringPossibleDriver(graph,m);
}
