//Find cycle in Directed Graph
/*
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

//We do DFS here and we use rec_stack for keeping track of elements
//alreay on current DFS path.It is different from undirected in the sense
//that here only using visited vector we can't tell if there is a backlink or 
//not.Eg: A ---> B---->C and A---->C.
//Here obviously C will already be visited but this downs't make a cycle
//Since there is no backlink pointing backwards on DFS path
//So we keep track of Path elements
bool cyclePresent(vector<bool> &visited, vector<bool>& rec_stack, int v, list<int>*& adj){
    //check if it is visited as well as in DFS path
    if(visited[v]){
        if(rec_stack[v])
            return true;
    }
    else{
        //if it is not visited then make it and add to recursion stack
        visited[v] = true;
        rec_stack[v] = true;
        
        //visit the adj. ones
        for(auto i: adj[v]){
            if(cyclePresent(visited, rec_stack, i, adj))
                return true;
        }
    }
    //remove the element from the recursion stack
    rec_stack[v] = false;
    return false;
}

bool Graph :: isCyclic()
{
    //visited vector
    vector<bool> visited(V,false);
    //make a stack for storing the elements along the current DFS path
    vector<bool> rec_stack(V,false);
    //do dfs and if at any time we encounter an already visited vertex
    //then a cycle is present

    for(int i = 0; i<V; i++)
        if(!visited[i] && cyclePresent(visited, rec_stack, i, this->adj))
            return true;
            
    return false;
}