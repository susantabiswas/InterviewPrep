/*The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.*/
string Solution::countAndSay(int n) {
    string str = "1";
    string temp;
    int j = 0;
    int c = 0;
    
    //start creating sequence by looking at the previous sequence
    for(int i = 0; i<n-1; i++){
        j = 0;
        //count occurences of each number and add it to the string 
        while( j <str.size()){
            c = 1;
            while( j+1 < str.size() && str[j] == str[j + 1]){
                ++c;
                ++j;
            }
            if(j >= str.size())
                break;
            temp += (char)(c + '0');
            temp += str[j];
            ++j;
        }
        str = temp;
        temp = "";
    }
    return str;
}
