/*
Given a chess board of order NxM and source points (s1,s2)
and destination points (d1,d2).
find min number of moves required by the Knight to go to the destination cell
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int x,y;
	int dist;
	Node( int a, int b, int d = 0){x = a; y = b;dist = d;}
};

//checking if the position is safe
bool isSafe(int i, int j, int& n, int& m){
	return i < n && i>=0 && j<m && j>=0 ;
}

//function for finding min moves
/*
	do bfs on positions as it will give the min path from starting
	to dest.Each position has 8 adj. positions which we can treat
	like adj vertices in  a graph
*/
int minMoves(int& s1, int& s2, int& d1, int& d2, int&n, int& m){
	//for keeping track of min moves
	int c = 0;
	bool found = false;
	//create a n X m chessboard
	//make a matrix for knowing the visited positions and mark all unvisited ini.
	vector< vector<bool>> visited(n, vector<bool>(m,false));

	//set of coordinates applicable for the knight
	vector<int> xcoor = {-1, 1, 2, 2, 1, -1, -2, -2};
	vector<int> ycoor = {2, 2, 1, -1, -2, -2, -1, 1};

	queue<Node> q;
	Node node(0,0,0);

	//push the starting position
	q.push(Node(s1,s2));
	visited[s1][s2] = true;
	while(!q.empty()){
		node = q.front();
		q.pop();

		visited[node.x][node.y] = true;

		if( node.x == d1 && node.y == d2){
			c = node.dist;
			found = true;
			break;
		}

		for(int i = 0; i<8; i++){
			if ( isSafe( node.x + xcoor[i], node.y + ycoor[i], n, m)
					&& !visited[ node.x + xcoor[i]][ node.y + ycoor[i]] ){
                q.push( Node(  node.x + xcoor[i],node.y + ycoor[i], node.dist + 1));
			}
		}

	}
	

	return found?c:-1;
}

int main(){
	int t,n,m;
	int s1,s2,d1,d2;
	cin >> t;
	while(t--){
		cin >> n >> m;
		//starting and dest coord.
		cin >> s1 >> s2 >> d1 >> d2;

		cout << minMoves(s1, s2, d1, d2, n, m) << endl;
	}
}
