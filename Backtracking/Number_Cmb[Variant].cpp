/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]*/
//using backtracking
void cmbSumMain(int l, int r, vector<int> arr, vector<int> &ans,
                vector<vector<int> >&sol, long int sum, int k){
    
    if( sum == k){
        sol.push_back(ans);
        return;
    }
    if(l >= r)
        return;
    for(int i = l; i<r; i++){
        //if the current sum becomes greater then further it is not possible
        if( sum + arr[i] > k)
            return;
        //when the current element is same as previous then,we will
        //get the same result since the previous element was backtracked 
        //and this is same as previous,so we skip it
        //NOTE: we only allow duplication when the element when we are using the
        //duplicates in succession ,like one was in previous recursive call
        //and the other in current recursive call and the final solution
        //will contain the same elements successively
        if(arr[i-1] == arr[i] && i>l)
            continue;
        ans.push_back(arr[i]);
        cmbSumMain(i+1, r, arr, ans, sol, sum + arr[i], k);
        ans.pop_back();
    }
}
//driver function
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    //sort the numbers
    sort(A.begin(),A.end());
    
    //for storing the solution
    vector< vector<int> >sol;
    vector<int> ans;
    int sum = 0;
    cmbSumMain(0, A.size(), A, ans, sol, sum, B);
    return sol;
}
