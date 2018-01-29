//Detect whether a Graph is Eulerian or not
/*
	Eulerian graph is one with a Eulerian Path.
	Euler path is that path which covers all the vertices exactly once

*/
/*
	This code uses Kosaraju's algo:

	1. do dfs from any vertex:
			if all vertices visited
				do step 2
			else
				return false;

	2. 	Make all vertices unvisited
		Transpose the graph(reverse the edges)
		Do DFS again from the same vertex and check if it still makes all
		vertices visited
		if yes
			then return true
		else
			return false

	If the graph is strongly connected then each vertex can be reached ,so if we
	reverse the edges even then if there is an path between then it will still be
	able to make you reach vertices
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	//for vertices
	int v;
	//for storing the edges
	list<int> *adj;
	//for edges
	int e;

public:
	Graph(int v, int e){
		this->v = v;
		this->adj = new list<int>[v];
		this->e = e;
	}

	void addEdge(int u, int v);
	void disp();
	Graph transposeGraph();
	bool kosarajuAlgo();
	void doDFS(int , vector<bool>&);
};


//for adding the edges
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

//for displaying the graph
void Graph:: disp(){

	list<int>::iterator it;
	for(int i = 0; i<v; i++){
		for(it = adj[i].begin(); it != adj[i].end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

//for doing DFS
void Graph::doDFS(int u, vector<bool>& visited){
	//make the current vertex as visited
	visited[u] = true;

	list<int>:: iterator it;
	//go for the adj. vertices
	for( it = adj[u].begin(); it!=adj[u].end(); it++){
		if(!visited[*it])
			doDFS(*it, visited);
	}
}

//for transposing the graph
Graph Graph:: transposeGraph(){
	//create a temporary object
	Graph g(this->v, this->e);

	list<int>::iterator it;
	for (int i = 0; i < this->v; ++i)
	{
		for(it = this->adj[i].begin(); it!= this->adj[i].end(); it++){
			g.adj[*it].push_back(i);
		}
	}

	return g;
}

//for doing the Kosaraju Algo
bool Graph::kosarajuAlgo(){
	//make a visited vector
	vector<bool> visited(this->v,false);

	//do DFS once
	doDFS(0, visited);

	//check if all the vertices are visited or not
	//if any one is also not visited then not strongly connected

	for(int i = 0; i<v; i++){
		if(!visited[i]){
			return false;
		}
		//make the all nodes unvisited again
		visited[i] = false;
	}

	//transpose the graph
	Graph newg = transposeGraph();

	//again do DFS from the same vertex as before
	//and check if all the vertces are visited or not
	newg.doDFS(0, visited);


	//check if all the vertices are visited or not
	for(int i = 0; i<v; i++)
		if(!visited[i])
			return false;
	return true;
}

int main(){
	 Graph g1(5,6);

	 g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);

    g1.kosarajuAlgo()? cout << "Yes\n" : cout << "No\n";

	 Graph g2(4,3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.kosarajuAlgo()? cout << "Yes\n" : cout << "No\n";

	return 0;
}





















