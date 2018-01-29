//DFS of Graph
#include<iostream>
#include<list>
using namespace std;

//graph class for graph
class graph
{
private:
	int ver;	//for storing the vertices of graph
	list<int> *adj;
public:
	graph(int v);
	void addEdge(int u,int v);
	void DFS(int start);
	void traverse(int ,bool visited[]);
};

//constructor
graph::graph(int v)
{
	this->ver=v;
	//make adjacency list for 'v' vertices
	adj=new list<int>[ver];
}

//adds the edge from 'u' to 'v'
void graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

//for traversing the adjacency list during DFS
void graph::traverse(int v,bool visited[])
{
	// display the vertex,and make it visited
	cout<<v<<" ";
    visited[v]=true;


	//traverse the rest of the vertices in the list
	list<int>::iterator i;

	for (i = adj[v].begin(); i!=adj[v].end(); ++i)
	{
		if(visited[*i]==false)
			traverse(*i,visited);
	}
}

//for doing DFS
//start:starting node for traversal
void graph::DFS(int start)
{
	bool visited[ver];
	//make every node unvisited
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
	}
    traverse(start,visited);
}


int main()
{
	//create graph
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 2);
    g.addEdge(1, 0);
    g.addEdge(3, 1);

    //DFS
    g.DFS(0);

	return 0;
}
