int Solution::strStr(const string &haystack, const string &needle) {
   //computer the LPS array
   vector<int> lps( haystack.size(), 0);
   int i = 1;
   int j = 0;
   int m = needle.size();
   int n = haystack.size();
   while(i < m){
       if(needle[i] == needle[j]){
           ++j;
           lps[i] = j;
           ++i;
       }
       else{
           if( j!= 0)
                j = lps[j-1];
            else{
                lps[i] = 0;
                ++i;
            }
       }
   }
   
   i = 0;
   j = 0;
   
   
   while( i < n){
       //if the characters match
       if( haystack[i] == needle[j]){
           i++,j++;
           if( j == m){
               return i - m;
           }
       }
       else{
           if( j!= 0)
                j = lps[j-1];
            else
                ++i;
       }
   }
   return -1;
}
