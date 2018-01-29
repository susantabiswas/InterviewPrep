//find the shortest path from a given vertex to all other vertices in a unweighted graph
/*
make an array of dist[ver],used to store the shortest distance of the nodes from the start ,then using BFS
we ensure that the node traversed currently is having the shortest distance as that is traversed using the
previous level node .
*/
#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph
{
private:
	int ver;
	list<int> *adj;
public:
	graph(int v)
	{
		this->ver=v;
		adj=new list<int>[ver];
	}
	void makeEdge(int u,int v);
	void shortestDistance(bool *visited,int start);
	void util(int start);
};

//for making the edges of the graph
void graph::makeEdge(int u,int v)
{
	adj[u].push_back(v);
}

//for finding  the shortest distance from the start node to all other nodes
void graph::shortestDistance(bool visited[],int start)
{
	//stores the shortest distance,initially all the distances are taken as zero
	int dist[ver];
	for(int i=0;i<ver;i++)
		dist[i]=1;
	dist[start]=0;

	//queue for BFS
	list<int> que;
	que.push_back(start);
	visited[start]=true;

	list<int>::iterator i;
	while(!que.empty())
	{
		start=que.front();
		que.pop_front();

		for(i=adj[start].begin();i!=adj[start].end();i++)
		{
			if(visited[*i]==false)
			{
				dist[*i]=dist[start]+1;
				que.push_back(*i);
				visited[*i]=true;
			}
		}
	}

	for(int i=0;i<ver;i++)
		cout<<"vertex "<<i<<":"<<dist[i]<<endl;

}

void graph::util(int start)
{
		bool visited[ver];
		for(int i=0;i<ver;i++)
			visited[i]=false;

		shortestDistance(visited,start);
}

int main()
{
	graph g(6);
/*
	 g.makeEdge(0, 1);
    g.makeEdge(0, 2);
    g.makeEdge(1, 2);
    g.makeEdge(2, 0);
    g.makeEdge(2, 3);
    g.makeEdge(3, 3);
	*/
	g.makeEdge(0, 1);
    g.makeEdge(0, 2);
    g.makeEdge(0, 3);
    g.makeEdge(2, 4);
    g.makeEdge(2, 5);

   g.util(0);

	return 0;
}
