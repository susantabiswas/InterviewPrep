/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]*/
//backtracking function


//Corner case: when there are duplicates
void cmbSum(int l, int r, vector<int> &A, int k, vector< vector<int>> &sol,
            long int sum, vector<int> &ans){
    
    if( sum == k){
        sol.push_back(ans);
        return;
    }
        
    //try the remaining numbers
    for(int i = l; i<r; i++){
        //since the numbers are sorted ,if the sum becomes greater than
        //k on adding the current number then it is not possible further
        if(i != 0 && A[i] == A[i-1])
            continue;
            
        if( sum + A[i] > k)
            return;
        ans.push_back(A[i]);
        cmbSum(i, r, A, k, sol, sum + A[i], ans);
        ans.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    //for storing the solution
    vector <vector<int> > sol;
    vector<int> ans;
    int sum = 0;
    cmbSum(0, A.size(), A, B, sol, sum, ans);
    return sol;
}
