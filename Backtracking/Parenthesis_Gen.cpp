/*Generate all Parentheses IIBookmark Suggest Edit
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.*/


//there are two options for each position:
//it can be ')' or '('
void genParenMain(int i, int o, int c, int n, string ans, vector<string> &sol){
    //when all the brackets are placed
    if( i >= 2*n){
        sol.push_back(ans);
        return;
    }

    //no. of opening braces shouldn't be greater than n
    if(o < n)
        genParenMain(i+1, o+1, c, n, ans + '(', sol);
    //no. of closing braces should not be greater than opening braces
    if(c < o)
        genParenMain(i+1, o, c+1, n, ans + ')', sol);
}
//driver function
vector<string> Solution::generateParenthesis(int A) {
    vector<string> sol;
    string ans;
    //for keeping track of closing brace
    int c = 0;
    //for opening brace
    int o = 0;
    //for keeping track of total brackets
    int i = 0;
    //unordered_map<string,int> h;
    genParenMain(i, o, c, A, ans, sol);
    return sol;
}
