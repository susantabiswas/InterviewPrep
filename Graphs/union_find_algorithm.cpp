// We will do union-find with weighted union and path compression for find
// Nice explanation: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for initializing arrays for union-find operations
void initialize(int N, vector<int>& arr) {
    arr.resize(N);
    
    for(int i = 0; i < N; i++) {
        arr[i] = i;
    }
}

// simple method to for finding the root of a node 
int findRoot(vector<int>& arr, int i) {
    // keep finding till current element is not root of itself
    while(arr[i] != i) {
        // go to root node 
        i = arr[i];
    }
    return i;
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
        arr[root_i] = root_j;
        num_nodes[root_j] += num_nodes[root_i];
        return root_j;
    }
}

// simple union operation
int unionOp(vector<int>& arr, int i, int j) {
    // we make the root of 'j' as parent of 'i'
    // parent(i) -> root(j)
    arr[i] = findRoot(arr, j);
    return arr[i];
}


// find operation
int findOp(vector<int>& arr, int i, int j) {
   // we can either use simple findRoot which takes O(logN) or 
   // path compression find which takes O(logN/2) ~ O(logN)
   return findRootPathCompression(arr, i) == findRootPathCompression(arr, j) ? 
          true : false;
}

int main() {
    // no. of vertices and edges 
    int N, M;
    cin >> N >> M;
    
    vector<int> arr;
    vector<int> num_nodes(N, 1);
    initialize(N, arr);
    
    int i, j;
    for(int k = 0; k < M; k++) {
        cin >> i >> j;
        weightedUnion(arr, num_nodes, i, j);  
    }
    
    return 0;
}
