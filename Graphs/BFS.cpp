//BFS of graph
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
	void BFS(int start);
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

//for BFS
void graph::BFS(int start)
{

	bool visited[ver];
	//make every node unvisited
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
	}

	//for storing the nodes at the same level
	list<int> queue;
	queue.push_back(start);
	visited[start]=true;

    list<int>::iterator i;
	//push the unvisited elements at the same level into the queue and display the front
	while(!queue.empty())
	{
		start=queue.front();
		cout<<start<<" ";
		queue.pop_front();
		for (i = adj[start].begin(); i!=adj[start].end(); ++i)
		{
			if(visited[*i]==false)
			{
				queue.push_back(*i);
				visited[*i]=true;
			}
		}
	}
}

int main()
{int v=5;
	//create  a graph
	graph g(v);

	//make edges for a directed graph
	 g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    //BFS
    g.BFS(0);

	return 0;
}
