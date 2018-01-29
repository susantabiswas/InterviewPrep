 //Find the longest path of all the vertices from the source vertex
/*The graph is a weighted graph.
Solution:Do topological sort to flatten the graph
		 then make all the distances of all vertices from source minus infinity
		 then for each vertex update the distance of its ajacent vertex from the source
*/

#include<iostream>
#include<list>
#include<stack>
#include<climits>
using namespace std;

class AdjList
{
private:
	int vertex;
	int weight;
public:
	//constructor
	AdjList(){vertex=weight=0;}
	AdjList(int v,int w){  vertex=v;  weight=w; }
	//for getting the vertex number
	int getVertex(){ return vertex;}
	//for getting the weight of vertex
	int getWeight(){ return weight;}
};

class Graph
{
private:
	int ver;
	list<AdjList> *adj;
public:
	//constructor
	Graph(int v)
	{
		ver=v;
		adj=new list<AdjList>[v];
	}
	void addEdge(int,int,int);
	void longestPath(int );
	void topologicalSort(int ,bool*,stack<int> &);
};

//adds an edge from u to v
void Graph::addEdge(int u,int v,int w)
{
	AdjList node(v,w);
	adj[u].push_back(node);
}

//for doing topological sort
void Graph::topologicalSort(int v,bool visited[],stack<int> &tempStack)
{
	visited[v]=true;

	list<AdjList>::iterator i;
	for (i = adj[v].begin(); i!=adj[v].end(); ++i)
		if(!visited[i->getVertex()])
			topologicalSort(i->getVertex(),visited,tempStack);

	tempStack.push(v);
}

//for calculating the longest distance of all the vertics from the source
void Graph::longestPath(int s)
{
	int u;
	bool visited[ver];
	//make all the vertices as non-visited
	for (int i = 0; i < ver; ++i)
	 {
	 	visited[i]=false;
	 }

	 stack<int> tempStack;
	 //do topological sort
	 for (int i = 0; i < ver; ++i)
	 {
	 	if(!visited[i])
	 		topologicalSort(i,visited,tempStack);
	 }

	 //for keeping track of distance of a vertex from source
	 int dist[ver];

	 //make distance of all the vertices except source as INT_MIN
	 for (int i = 0; i < ver; ++i)
	 	dist[i]=INT_MIN;

	 dist[s]=0;
	 while(!tempStack.empty())
	 {
	 	u=tempStack.top();
	 	tempStack.pop();

        //update the distances of vertices
	 	list<AdjList>::iterator i;
	 	if(dist[u]!=INT_MIN)
            for (i = adj[u].begin();i!=adj[u].end(); ++i)
            {
                if(dist[i->getVertex()]<dist[u] + i->getWeight())
                    dist[i->getVertex()]=dist[u]+i->getWeight();

            }
	}

	//print the path distances
	for (int i = 0; i < ver; ++i)
	{
	    if(dist[i]==INT_MIN)
            cout<<"Infinity  ";
        else
            cout<<dist[i]<<" ";
	}
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
	return 0;
}
