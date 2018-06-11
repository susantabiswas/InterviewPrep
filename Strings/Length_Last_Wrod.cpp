/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.*/


/*
Traverse from the end and go till the first non-space character
since there can be space after the last word also
then starrt counting till the first space
*/
int Solution::lengthOfLastWord(const string &A) {
   int  c = 0;
   int i = A.size() - 1;
   //ignore all spaces from end
   while(A[i] == ' ')
    --i;
   while(i >= 0 && A[i] != ' '){
       ++c;
       --i;
   }
   return c;
}
