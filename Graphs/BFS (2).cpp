//BFS
//directed Graph representation using adjacency list
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

//structure for node
struct Node{
	//for storing vertex info.
	int v;
	Node* next;
};

//creates a node
Node* createNode(int v){
	Node* node = new Node;
	node->v = v;
	node->next = NULL;
	return node;
}

//structure for graph
struct Graph{
	//total vertices
	int ver;
	//total edges
	int edges;
	//vector of vertices for storing their edges
	vector< list<int> > arr;

};

//for creating a graph
Graph* createGraph(int ver, int ed){
	Graph *g = new Graph;
	g->ver = ver;
	g->edges = ed;
	g->arr.resize(ver);
	//for(int i = 0; i<ver; i++)
	//	g->arr[i] = NULL;
	return g;
}

//for  adding edges
void addEdge(Graph* g, int u, int v){
	if(g == NULL){
		cout << "graph not created yet !\n";
		return;
	}
	
	g->arr[u].push_back(v);
}

//prints the adj list
void printAdjList1(Graph* g){
	list<int>::iterator it;
	for (int i = 0; i < g->ver; ++i)
	{
		for(it = g->arr[i].begin(); it!=g->arr[i].end(); it++)
			cout<<*it<< " ";
		cout << endl;
	}
}

//BFS 
void BFS(Graph* g){
	if(g == NULL)
		cout << "Graph doesn't exist\n";
	else{
		//for marking visited vertices
		vector<bool> visited(g->ver,false);
		//for storing vertices
		queue<int> q;
		//start with  vertex 0
		q.push(0);
		int v ;
		while(!q.empty()){
			v = q.front();
			  
		}
	}
}

int main(){
	Graph *g = createGraph(5,7);
	addEdge(g,0,1);
	addEdge(g,0,4);
	addEdge(g,1,2);
	addEdge(g,3,1);
	addEdge(g,3,2);
	addEdge(g,4,1);
	addEdge(g,4,3);

	printAdjList1(g);
}
