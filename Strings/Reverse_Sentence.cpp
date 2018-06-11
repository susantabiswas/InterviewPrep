/*Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".*/

//for reversing the word
void reverse(string& str, int i, int j){
    char t;
    while( i < j){
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        ++i, --j;
    }

}

/*
    algo:
    1.reverse the entire sentence
    2.reverse the individual words
*/
void Solution::reverseWords(string &str) {
    
    //first reverse the entire string
    int i = 0; int j = str.size() - 1;
    char t;
    while( i < j){
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        --j,++i;
    }
    //then reverse the individual words
    //find the starting index of a word and its ending index
    i = 0;
    int n = str.size();
    while(i < n ){
        //if it is space then skip it
        if( str[i] == ' ')
            ++i;
        else{
            j = i;
            //since the starting index of the word has been found , find the 
            //ending index next
            while( j < n && str[j] != ' '){
                ++j;
            }
            reverse(str, i, j-1);
           
            if(j == n)
                break;
            else
                i = j + 1;
        }
    }
    
}
