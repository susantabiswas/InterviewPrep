//check whether a graph is bipartite or not
/*A graph is bipartite if the adjacent vertces can be coloured in two different colours and no two adjacent vertices
has the same colour.
Do BFS and colour the uncoloured vertices ,if two adjacent vertices are of same colour then false else keep alternate colouring the
adjacent vertices*/

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
	bool checkBipartite(int start);
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

//for checking whether the graph is bipartite or not
bool graph::checkBipartite(int start)
{
	bool visited[ver];
	//for denoting whether coloured or not
	int coloured[ver];
	//make every node unvisited
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
	}

	// -1 means uncoloured ,1 and 0 are two different colours
	for (int i = 0; i < ver; ++i)
	{
		coloured[i]=-1;
	}

	//for storing the nodes at the same level
	list<int> queue;
	queue.push_back(start);
	visited[start]=true;
	coloured[start]=0;

    list<int>::iterator i;
	//push the unvisited elements at the same level into the queue and display the front
	while(!queue.empty())
	{
		start=queue.front();
		queue.pop_front();

		for (i = adj[start].begin(); i!=adj[start].end(); ++i)
		{
			//if the node is unvisited and uncoloured,then colour it with a alternate colour then that of its adjacent edge
			if(visited[*i]==false)
			{
				queue.push_back(*i);
				visited[*i]=true;
				coloured[*i]=coloured[start]-coloured[*i];
			}
			//if the node is visited and has the same colour as that of the adjacent node then not bipartite
			else if(visited[*i] && coloured[*i]==coloured[start])
				return false;
		}
	}
	return true;
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

    if(g.checkBipartite(0))
    	cout<<"The graph is Bipartite\n";
    else
    	cout<<"It is not Bipartite\n";

	return 0;
}
