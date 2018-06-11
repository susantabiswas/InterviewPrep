/*Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]*/

//bactracking function
void combineMain(int l, int r,  vector<int> &num, vector<int> &ans, 
                vector< vector<int> > &sol, int k){
    if( l >=r )
        return;
    
    //include the current number once
    ans.push_back(num[l]);
    
    //check if the current size satisfies the condition
    if(ans.size() == k)
        sol.push_back(ans);
    else
        combineMain(l+1, r, num, ans, sol, k);
        
    //exclude the current element
    ans.pop_back();
    combineMain(l+1, r, num, ans, sol, k);
}
vector<vector<int> > Solution::combine(int n, int k) {
   //make a vector of n numbers
   vector<int> num(n);
   //fill the vector
   for(int i = 1; i<=n; i++)
        num[i-1] = i;
    
    //make a solution vector
    vector< vector<int> > sol;
    //temp vector
    vector<int> ans;
    
    combineMain(0, n, num, ans, sol, k);
    return sol;
}
