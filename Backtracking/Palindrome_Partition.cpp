/*Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")*/

//check if it is palindrome or not
bool isPalin(string str){
    if(str.size() == 1 )
        return true;
    if(str.size() == 0)
        return false;
        
    for(int i = 0,j = str.size()-1; i<j; i++,j--)
        if(str[i] != str[j])
            return false;
    return true;    
}

//using backtracking 
void partitionMain(string str, vector<string > &ans, vector<vector<string>> &sol){
    //when there is only element then it is a palindrome
    if(str.size() == 1 ){
        ans.push_back(str);
        sol.push_back(ans);
        ans.pop_back();
        return;
    }
    if(str.empty()){
        sol.push_back(ans);
        return;
    }
    //check for each substring if they form a palindrome or not
    //if it forms a palindrome then check for the rest using recursion
    for(int i = 0; i<str.size(); i++){
        if( isPalin( str.substr(0, i+1 ) ) ){
            
            ans.push_back( str.substr(0,i+1) );
            partitionMain(str.substr(i+1), ans, sol);
            ans.pop_back();
        }
    }
}

//driver function
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > sol;
    vector<string> ans;
    partitionMain(A, ans, sol);
    return sol;
}
