/*Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . 
find whether there is a path possible from source to destination, 
while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note : there is only single source and single destination.
 
Examples:

Input : M[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
Output : Yes

Input : M[4][4] = {{ 0 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};
Output : Yes
*/
#include<bits/stdc++.h>
using namespace std;

//for checking whether the current position is safe for moving ahead or not
bool isSafe(int i, int j, int& n,vector< vector<int>>& g){

	return i < n && i>=0 && j <n && j>=0 && g[i][j];
}

//does DFS from and stops when it finds the dest end
bool pathPossible(vector< vector<int>>& g, int &n, 
                vector< vector<bool>>& visited, int i, int j, int& di, int& dj){
                    
	//make the current as visited
	visited[i][j] = true;

	//check if it is dest or not
	if(i == di && j == dj)
		return true;

	//coordinates for the 8 directions
    vector<int> x = {-1,0,1,-1,1,-1,0,1};
    vector<int> y = {1,1,1,0,0,-1,-1,-1};

    for(int k = 0; k<8; k++){
    	if(isSafe(i + x[k], j + y[k], n, g) && !visited[i + x[k]][j + y[j]])
    		if(pathPossible(g, n, visited, i + x[k], j + y[k], di, dj))
    			return true;
    }
	return false;
}


//driver for finding the path possible func
bool pathPossibleDriver(vector< vector<int> >& g, int &n, int& si, int& sj,
                        int& di, int& dj){
	//make a visited matrix
	//mark all as unvisited
	vector< vector<bool>> visited(n, vector<bool>(n));
    
	//start DFS from start to the dest ,we take the 8 neigh.of each as 
	//the adj. elements of each elements
	return pathPossible(g, n, visited, si, sj, di, dj);
}

int main(){
	int t,n;
	int si,sj,di,dj;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		//make the graph
		vector< vector<int> > g(n, vector<int>(n));

		//take elements
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++){
				cin >> g[i][j];
				//if it is the start then take its position
				if(g[i][j] == 1){
				    si = i; 
				    sj = j;
				}
				//if it is the dest then take its position
				if(g[i][j] == 2){
				    di = i; dj = j;
				}
			}
cout <<"di,dj:"<<di<<dj<<" si,sj:"<<si<<sj<<endl;
		cout << pathPossibleDriver(g, n, si, sj, di, dj) << endl;
	}
}
