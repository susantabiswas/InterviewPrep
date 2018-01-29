//given a graph G,find whether a hamiltonian cycle is present or not in the graph.
//A hamiltonian path is the path that covers each vertex exactly once
//and a hamiltonian cycle is that hamiltonian path where there is an edge from
//the last node to the starting node
#include<iostream>
#include<vector>
using namespace std;

//prints the hamiltonian path
void printPath(vector<int> path){
	for (int i = 0; i < path.size(); ++i)
	{
		cout<<path[i]<<" ";
	}
	cout<<endl;
}


//checks if a node can be considered for being part of hamiltonian path
bool isSafe(vector<int> path, int curr_v, int count){
	for (int i = 0; i < count; ++i)
	{
		if(path[i] == curr_v)
			return false;
	}
	return true;
}

bool hamiltonianCycle(vector< vector<bool> > &graph, vector<int> &path,
					 int curr_v, int count){
	//when all nodes are visited and the start node has an edge with the 
	//last node
	if (count >= graph[0].size() && graph[curr_v][path[0]] == true)
		return true;

	//for each vertex visit its adjacent vertices
	for (int i = 0; i < graph[0].size(); ++i)
	{
		//whether there is an edge with the vertex or not
		if(graph[curr_v][i] == true){
				//check for that vertex
			if(isSafe(path, i, count)){
				//add the vertex to the path
				path[count] = i;

				if(hamiltonianCycle(graph,path,i,count+1))
					return true;

			}
		}
	}
	return false;
}

///driver function for finding the presence of hamiltonian cycle in a graph
void hamiltonianCycleDriver(vector< vector<bool> > &graph){
	//for keeping track of sequence of vertices already covered ,initially all are marked as unvisited
	vector<int> path(graph[0].size(),-1);

	//for keeping track of vertices visited
	//we start with the first node 0
	int count = 0;
	//shows that the first node for the hamiltonian path is 0
	path[count] = 0;
	int curr_v = 0;
	if( hamiltonianCycle(graph,path,curr_v,count+1))
		printPath(path);
	else
		cout<<"No hamiltonian cycle is present\n";
}

int main(){
	/* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   vector<vector<bool> >graph1 = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

    hamiltonianCycleDriver(graph1);

   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    vector<vector<bool> >graph2 = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };

	hamiltonianCycleDriver(graph2);
}
