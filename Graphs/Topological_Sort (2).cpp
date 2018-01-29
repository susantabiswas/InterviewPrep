//Do topological sort

//for doing DFS ,also detects if a cycle is present or not 
bool doDFS(int v, vector<int> graph[], int& N, vector<bool>& visited, 
                                stack<int>& s, vector<bool>& rec_stack){
    //if it is visited  then check if it is on recursion stack or not
    if(visited[v]){
        if(rec_stack[v])
            return true;
    }                   
    //when it is not on recursion stack
    else{
        //make it visited
        visited[v] = true;
        rec_stack[v] = true;
        
        //visit the adj. elements
        for(int i = 0; i<N; i++){
            if(graph[v][i] && doDFS(i, graph, N, visited, s, rec_stack)){
                return true;
            }
        }
        s.push(v);
    }
    rec_stack[v] = false;
    return false;
}
int * topoSort(vector<int> graph[], int N)
{
    int i = 0;
    //make a stack for storing the order
    stack<int> s;
    bool topSortPoss = true;
    //for keeping track of visited elements
    vector<bool> visited(N, false);
    
    //since there can be a cycle also in the directed graph
    //we use a recursion stack for keeping track of elements already on the 
    //DFS path
    vector<bool> rec_stack(N, false);
    int arr[N];
    ///then do DFS ,now in DFS we do go on doing DFS and go deeper then
    //then push the element into the stack this way in the end the element
    //from which all others were made to go DFS will be on Top and we will 
    //get the req. order
    for(int j = 0; j<N; j++){
        if(!visited[j]){
            if(!doDFS(j, graph, N, visited, s, rec_stack)){
                //there is no cycle so now take out the elements and 
                //put in a array
                
                
                while(!s.empty()){
                    arr[i++] = s.top();
                    s.pop();
                }
            }
            else
                topSortPoss = false;
        }
    
    }    
    
    cout << topSortPoss<<endl;
    return arr;
}