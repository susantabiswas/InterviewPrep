/*Given a digit string, return 
all possible letter combinations that the number could represent.
The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

//for mapping keys
void doMapping( vector<string> &h){
    h[0] = "0";
    h[1] = "1";
    h[2] = "abc";
    h[3] = "def";
    h[4] = "ghi";
    h[5] = "jkl";
    h[6] = "mno";
    h[7] = "pqrs";
    h[8] = "tuv";
    h[9] = "wxyz";
    
}

//using backtracking 
/*
    Each number can have either 1/3/4 options so try them for the suitable case
    start with each number and try all its cmb and continue in similar manner
*/
void letterCmbMain(int l, int r, string str, vector<string> &h,
                    vector<string> &sol, string ans){
    //when the string combination has finished
    if(l >= r){
        sol.push_back(ans);
        return;
    }    
    
    //try all its mappings
    string mappings = h[ str[l] - '0' ];
    for(int i = 0; i < mappings.size(); i++){
        letterCmbMain(l+1, r, str, h, sol, ans + mappings[i]);
    }
    
}

//driver function
vector<string> Solution::letterCombinations(string A) {
    
    //hash map for keys and their char associ.
    vector<string> h(10);
    //create the hash map
    doMapping(h);
    
    //for storing the solution
    vector<string> sol;
    string ans;
    letterCmbMain(0, A.size(), A, h, sol, ans);
    return sol;
}
