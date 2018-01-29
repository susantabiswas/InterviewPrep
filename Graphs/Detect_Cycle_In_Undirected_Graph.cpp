//Detect Cycle in an Undirected graph
/*Detecting a cycle in an undirected graph is different from directed,because in undirected graph
each link between two nodes have a bidirectional edge ,which makes a loop,so to avoid such cases the concept
of parent node is there.
*/
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
	bool checkCycle(int ,bool*,int);
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
bool graph::checkCycle(int v,bool *visited,int parent)
{
		visited[v]=true;

		list<int> ::iterator i;
		for (i = adj[v].begin(); i!=adj[v].end(); ++i)
		{
		    //when an unvisited node has a repeated element this becomes false else if non-repeated element then true
		    if(!visited[*i])
                if(checkCycle(*i,visited,v))
                    return true;

            //if the current node is visited and it is not parent
			else if(*i!=parent)
				return true;
		}
    return false;
}

//Driver function for checking cycle in the vertices
bool graph::checkCycleDriver()
{
	//for keeping track of all the visited nodes
	bool visited[ver];

	//make all the vertices unvisited
	for (int i = 0; i < ver; ++i)
	{
		visited[i]=false;
	}

	//traverse for each node in the graph
	for (int v = 0; v<ver; ++v)
       if(!visited[v])
        if(checkCycle(v,visited,-1))
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
    g.addEdge(1, 0);
    g.addEdge(3, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(4, 4);


    if(g.checkCycleDriver())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
	return 0;
}

