//Do the Topological sort of a graph
/*This is Different form DFS as in DFS we print each level as we recurrsively go down,but here we store all
the nodes till the deepest level and then print from the deepest level
*/
#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
private:
	int ver;	//No. of vertices of Graph
	list<int> *adj;
public:
	Graph(int v)
	{
		ver=v;
		adj=new list<int>[ver];
	}
	void addEdge(int u,int v);
	void topologicalSortDriver();
	void topologicalSort(int,bool*,stack<int>&);
};

//for adding a new edge to the graph
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

//for doing the topological sort
void Graph::topologicalSort(int v,bool visited[],stack<int> & tempStack)
{
	visited[v]=true;
	list<int>::iterator i;

	for (i = adj[v].begin(); i!=adj[v].end(); ++i)
	{
		if(!visited[*i])
		{
			topologicalSort(*i,visited,tempStack);
		}
	}
	tempStack.push(v);
}

//for facilitating the topological sort
/*Here DFS for the all vertices are done */
void Graph::topologicalSortDriver()
{
	bool visited[ver];
	//make all the vertices not visited initially
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
	}

	//for temporary storage of node as we go down the levels during DFS
	stack <int> tempStack;

	//for each vertex of graph
	for (int i = 0; i < ver; ++i)
	{
		if(!visited[i])
			topologicalSort(i,visited,tempStack);
	}

	//now display the stack elements
	while(!tempStack.empty())
	{
		cout<<tempStack.top()<<" ";
		tempStack.pop();
	}
}

int main()
{

    //create graph
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 2);
    g.addEdge(1, 0);
    g.addEdge(3, 1);

    g.topologicalSortDriver();
	return 0;
}
