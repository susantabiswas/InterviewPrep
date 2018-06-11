/*Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]*/

void subsetMain(int l, int r, vector<int> &ans, vector<int> &A, 
                vector< vector<int> > &sol){
    if(l >= r){
        return;
    }
    
    //every element has two options either include it or exclude it
    //try including the element and excluding the element once 
    ans.push_back(A[l]);
    //when we check for the duplicate element
    //if there are duplicates then their self is also considered a subset
    //but it will create a duplicate subset,we avoid that
   
    sol.push_back(ans);
    subsetMain(l+1, r, ans, A, sol);
    ans.pop_back();
    while(l+1 < r && A[l] == A[l+1])
        l++;
    subsetMain(l+1, r, ans, A, sol);
    
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    sort(begin(A),end(A));
    vector< vector<int> > sol;
    vector<int> ans;
    sol.push_back(ans);
    subsetMain(0, A.size(), ans, A, sol);
    return sol;
}
