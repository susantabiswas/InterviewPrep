//Detect Cycle in a directed graph
#include<iostream>
#include<list>
using namespace std;

class graph
{
private:
	int ver;
	list<int> *adj;
public:
	graph(int v)
	{
		ver=v;
		adj=new list<int>[ver];
	}
	void addEdge(int ,int);
	bool checkCycle(int ,bool*,bool*);
	bool checkCycleDriver();
};

void graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

//checking whether there is a cycle in a list
/*if a node is already visited then there are 2 possiblities:
	1.that node makes a cycle
	2. there is a false cycle
		0->2
		0->1->2,this is not cyclic but appears to be
    NOTE:cyclic node will always be detected as cyclic on its first visit
*/
bool graph::checkCycle(int v,bool *visited,bool *stackElement)
{
	//if the node is not visited
	if(!visited[v])
	{
		visited[v]=true;
		stackElement[v]=true;

		list<int> ::iterator i;
		for (i = adj[v].begin(); i!=adj[v].end(); ++i)
		{
		    //when an unvisited node has a repeated element this becomes false else if non-repeated element then true
			if(!visited[*i] && checkCycle(*i,visited,stackElement))
				return true;
			else if(stackElement[*i])
				return true;
		}
	}
	stackElement[v]=false;
	return false;
}

//Driver function for checking cycle in the vertices
bool graph::checkCycleDriver()
{
	//for keeping track of all the visited nodes
	bool visited[ver];
	//for seeing whether in a DFS any of the root node reappears or not
	bool stackElement[ver];

	//make all the vertices unvisited
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
		stackElement[i]=false;
	}

	//traverse for each node in the graph
	for (int v = 0; v<ver; ++v)
        if(checkCycle(v,visited,stackElement))
            return true;

	return false;
}

int main()
{
    // Create a graph given in the above diagram
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 4);

    if(g.checkCycleDriver())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
	return 0;
}
