/*Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.

Example:

Given the array as:

[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
The answer would be “a”.*/

string Solution::longestCommonPrefix(vector<string> &A) {
    //sort the array
    sort(A.begin(), A.end());
    
    string lcp;
    lcp = A[0];
    int j = 0;
    for(int i = 1; i< A.size(); i++){
        //check if the current prefix is there or not
        for( j = 0; j<lcp.size(); j++){
            if(lcp[j] != A[i][j])
                break;
        }
        //make the new lcp
        lcp = A[i].substr(0, j );
    }
    return lcp;
}
