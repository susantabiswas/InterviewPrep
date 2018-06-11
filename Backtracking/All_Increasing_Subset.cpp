/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/
//for checking if the current subset is valid
bool isSafe(vector<int> &ans){
    //check if the numbers are sorted
    for(int i = 1; i<ans.size(); i++){
        if(ans[i-1] > ans[i])
            return false;
    }
    return true;
}

//for each number we have 2 options: either include it or remove it
void subFunction(int l, int r, vector<int> &A,
                vector<vector<int> > &sol, vector<int> &ans){
    if(l >= r )
        return;
    
    //include the number
    ans.push_back(A[l]);
    if(isSafe(ans)){
        sol.push_back(ans);
        subFunction(l+1, r, A, sol, ans);
    }
  
    //don't include the number
    ans.pop_back();
    subFunction(l+1, r, A, sol, ans);
    
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    vector< vector<int> > sol;
    vector<int> ans;
    sol.push_back(vector<int>{});
    subFunction(0,n,A,sol,ans);
    return sol;
}
