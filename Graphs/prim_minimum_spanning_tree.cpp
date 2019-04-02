/*
	Prim's Minimum spanning tree:

	Here two sets are maintained, one which has all the vertices and other is empty initially
	
	With each vertex we associate the cut cost
	make starting node's cut cost = 0
	while all the nodes are visited:
		pick the vertex with least cut cost, if it is unvisited
		add to mst set
		mark it visited

	inorder to prevent cycle we check if nodes are visited
	TC: O((E+V)logV)

	Here we do union by rank and root finding by path compression
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

	vector<vector<Edge> > mst(N);

	// in BFS manner we add vertices to priority queue by pushing their updated cut cost
	while(!min_heap.empty()) {
		Edge e = min_heap.top();
		min_heap.pop();

		// check if it has already been visited or not
		if(visited[e.start] == false) {
			// mark it as visited
			visited[e.start] = true;
			// add to MST
			mst.emplace_back(e);

			// add all its adjacent edges if they are not visited
			for(const auto& edge: g[e.end])
				if(visited[edge.end] == false)
					min_heap.emplace(edge);
		}
	}

	
	return mst;
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
	}
    
    displayGraph(g);
    
	// create MST using Kruskal's algo
	auto mst = primMST(g);
	displayGraph(mst);
	return 0;
}
