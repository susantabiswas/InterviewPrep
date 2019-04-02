/*
	Kruskal's Minimum spanning tree:

	till V-1 edges are there:
		1. pick the smallest weight edge
		2. check if on adding it can cause a cycle or not to the existing edges in MST
		3. repeat step 2

	TC: O(ElogE) sorting + O(ElogV) union operation

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

// for initializing arrays for union-find operations
void initialize(int N, vector<int>& arr) {
    arr.resize(N);
    
    for(int i = 0; i < N; i++) {
        arr[i] = i;
    }
}

// for doing find operation with path compression
int findRootPathCompression(vector<int>& arr, int i) {
   // we take two steps upwards
   while(arr[i] != i) {
       arr[i] = arr[arr[i]];
       i = arr[i];
   }
   return i;
}

// for doing weighted union operation
int weightedUnion(vector<int>& arr, vector<int>& num_nodes, int i, int j) {
    // here to decide whose root should be the root of merged
    // subset we consider the size of current subsets of i and j
    
    // first find the roots of both
    int root_i = findRootPathCompression(arr, i);
    int root_j = findRootPathCompression(arr, j);
    
    // when they already belong to the same subset
    if(root_i == root_j)
    	return root_i;
    	
    if(num_nodes[root_j] > num_nodes[root_i]) {
        // make root of j as parent of i
        arr[root_i] = root_j;
        // update the size of new subset
        num_nodes[root_j] += num_nodes[root_i];
        return root_j;
    }
    else if(num_nodes[root_j] < num_nodes[root_i]) {
        // make root of i as parent of j
        arr[root_j] = root_i;
        // update size of new subset
        num_nodes[root_i] += num_nodes[root_j];
        return root_i;
    }
    else if(num_nodes[root_j] == num_nodes[root_i]) {  // both subsets are of same size
        arr[root_i] = arr[root_j];
        return root_j;
    }
}

// find operation
int findOp(vector<int>& arr, int i, int j) {
   // we can either use simple findRoot which takes O(logN) or 
   // path compression find which takes O(logN/2) ~ O(logN)
   return findRootPathCompression(arr, i) == findRootPathCompression(arr, j) ? 
          true : false;
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

vector<vector<Edge> > kruskalMST(vector<vector<Edge> >& g) {
	const int N = g.size();
	// contains root info for each node, required for union find ops
    vector<int> arr;
    vector<int> num_nodes(N, 1); // rank info for each subset
    initialize(N, arr);
    
	vector<vector<Edge> > mst(N);

	vector<Edge> edges;

	for(int i = 0; i < g.size(); i++) {
		for(int j = 0; j < g[i].size(); j++)
			edges.emplace_back(g[i][j]);
	}
	
	// sort the edges acc to weight
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)->bool{
		return a.weight < b.weight;	
	});
	
	int curr = 0;
	
	// add edges till there are N-1 edges in MST
	int e = 0;
	while(e < N - 1) {
		// min weight edge
		Edge min_edge = edges[curr++];
		
		// check if adding this will create a cycle or not
		// current edge will be added only if it doesnt create a cycle
		if(findOp(arr, min_edge.start, min_edge.end) == false) {
			mst[min_edge.start].emplace_back(min_edge);
			weightedUnion(arr, num_nodes, min_edge.start, min_edge.end);
			++e;
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
	auto mst = kruskalMST(g);
	displayGraph(mst);
	return 0;
}
