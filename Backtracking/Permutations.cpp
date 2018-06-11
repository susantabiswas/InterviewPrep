//using backtracking
//swap positions with the starting position for the remaining indices
//In each recursive call start position becomes +1 of previous start pos
void permuteMain(int l, int r, vector<int> &A, vector<int> &ans, 
                    vector<vector<int>> &sol){
    if( l >= r ){
        sol.push_back(A);
        return;
    }
    
    //for swapping
   int t ; 
   for(int i = l; i<r; i++){
       //swap numbers
       int t = A[l];
       A[l] = A[i];
       A[i] = t;
       
       permuteMain(l+1, r, A, ans, sol);
       
       //revert back
       int t = A[l];
       A[l] = A[i];
       A[i] = t;
   }
}

//driver function
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector< vector<int> > sol;
    vector<int> ans;
    permuteMain(0, A.size(), A, ans, sol);
    return sol;
}
