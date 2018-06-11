/*Minimum Characters required to make a String PalindromicBookmark Suggest Edit
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2
*/

/*
    If we have a palindrome then on attaching the reverse of that palindrome then 
    on computing the lps of the combined string the last value is equal to the 
    original string length this is because on reversing the entire reversed string (suffix)
    should be equal to the prefix  that is the original string if it is a palindrome
    
    Now the if the last character's lps value is not equal to the original string length
    then that means there are characters which are missing that should be equal 
    to the reversed string's characters
*/
int Solution::solve(string str) {
    //for storing the original + '$' + reversed string
    string comb;
    comb += str;
    //sentinal character to differentiate the two strings
    comb += '$';
    
     //create a lps array for the combined string
    vector<int> lps(2*str.size() + 1,0);

    //now add the reversed string
    for(int i = str.size() - 1; i >= 0; i--)
        comb += str[i];
        
    //calculate the lps array
    //Computing the lps after the $ is enough
    //we place i at pos($) + 1 and j = 0
    int i = str.size() + 1;
    int j = 0;
    
    while( i < comb.size()){
        //when the chars matches
        if( comb[i] == comb[j]){
            ++j;
            lps[i] = j;
            ++i;
        }
        else{
            if( j != 0)
                j = lps[ j - 1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    
    //if it is a plaindrome then the last value of lps should be original string length,
    //if not that means that many characters are missing
    return str.size() - lps[ lps.size()-1];
}
