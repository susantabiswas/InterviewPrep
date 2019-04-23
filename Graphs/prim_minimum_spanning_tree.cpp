/*
	Prim's Minimum spanning tree:

	Here two sets are maintained, one which has all the vertices and other is empty initially
	
	With each vertex we associate the cut cost
	make starting node's cut cost = 0
	while all the nodes are unvisited:
		pick the vertex with least cut cost, if it is unvisited
		add to mst set
		mark it visited

	inorder to prevent cycle we check if nodes are visited
	TC: O((E+V)logV)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

// edge structure
struct Edge {
	int start, end, weight;
	Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
};

// finds the MST using Prim's algo
vector<vector<Edge> > primMST(vector<vector<Edge> >& g) {
	const int N = g.size();

	// min heap for the edges
	priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)> >
		min_heap([](const Edge& a, const Edge& b)->bool{
			return a.weight > b.weight;
		});

	// for marking visited vertices
	vector<bool> visited(N, false);

	// add all the edges of starting vertex
	for(const auto& e: g[0])
		min_heap.emplace(e);
	// mark the starting vertex visited
	visited[0] = true;
	
	vector<vector<Edge> > mst(N);

	// in BFS manner we add edges for current vertex and each time pick the smallest weight edge
	while(!min_heap.empty()) {
		Edge e = min_heap.top();
		min_heap.pop();
		
		// check if it has already been visited or not
		if(visited[e.end] == false) {
			// mark it as visited
			visited[e.end] = true;
			// add to MST
			mst[e.start].emplace_back(e);

			// add all its adjacent edges if they are not visited
			for(const auto& edge: g[e.end]) {
				if(visited[edge.end] == false) {
					min_heap.emplace(edge);
				}
			}
		}
	}

	
	return mst;
}


void displayGraph(vector<vector<Edge> >& g) {
	for(int i = 0; i < g.size(); i++) {
		cout << i << ": ";
		for(int j = 0; j < g[i].size(); j++)
			cout << "(" << g[i][j].end <<", " <<g[i][j].weight<<")  ";
		cout << endl;
	}
	cout << endl;	
}

int main() {
    // no. of vertices and edges 
    int N, M;
    cin >> N >> M;
    
	// create a graph
	vector<vector<Edge> > g(N);

	int a, b, w;
	// add edges
    for(int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		g[a].emplace_back(Edge{a, b, w}); 
		g[b].emplace_back(Edge{b, a, w}); 
	}
    
    displayGraph(g);
    
	// create MST using Prim's algo
	auto mst = primMST(g);
	displayGraph(mst);
	return 0;
}
