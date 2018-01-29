/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};*/
/*You are required to complete this method*/

//Do DFS and if a visited vertex is encountered then return true
//In undirected graph if there is an edge between u and v then u has v as
//adj and v has u as adj.So obviously when the dfs for the adj of curr will happen
//then in its turn it will again see that previous curr as its adj. and it will be visited
//but is not actually a cycle ,so for each vertex will use "prev" which conatins
//the previous node from which it was called
bool cyclePresent(vector<bool> &visited, int v, list<int>*& adj, int prev){
    //check if already visited or not
    if(visited[v])
        return true;
    //else mark as visited
    visited[v] = true;
    
    //visit the adj vertices
    for(auto i: adj[v]){
        if(i != prev)
            if(cyclePresent(visited, i, adj, v))
                return true;
    }
    return false;
}

bool Graph :: isCyclic()
{
    //visited vector
    vector<bool> visited(V,false);
    
    //do dfs and if at any time we encounter an already visited vertex
    //then a cycle is present

    for(int i = 0; i<V; i++)
        if(!visited[i] && cyclePresent(visited, i, this->adj,-1))
            return true;
            
    return false;
}