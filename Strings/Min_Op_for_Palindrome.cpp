/*Minimum Characters required to make a String PalindromicBookmark Suggest Edit
Problem Setter: glowing_glare 
Problem Tester: RAMBO_tejasv
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2*/

int Solution::solve(string str) {
    int i = 0;
    int j = str.size()-1;
    int t;
    
    while(i<str.size() && j >=0 && i<j){
        if(str[i] == str[j]){
            i++;
            --j;
        }
        else if(str[i] != str[j]){
            t = str.size() - j - 1;
            i = 0;
        }
        
    }
    return t;
}
