/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.*/

string Solution::addBinary(string A, string B) {
    int c = 0;
    string res;
    int digit = 0;
    int i = A.size() - 1;
    int j = B.size() - 1;
    
    while( i>=0 && j>=0 ){
        digit = c + (A[i] - '0') + (B[j] - '0');
        //if the digits sum upto 2 i.e 1 + 1 + 0 then digit is 0 and carry 1
        if(digit == 2){
             c = 1;
             digit = 0;
        }
        //if the digits sum upto 2 i.e 1 + 1 + 1 then digit is 1 and carry 0
        else if( digit == 3){
            c = 1;
            digit = 1;
        }
        //reset the carry when the digits are zero
        else
            c = 0;
        res += (digit + '0');
        --i,--j;
    }
    
    while( i>= 0){
        digit = c + (A[i] - '0');
        if(digit == 2){
             c = 1;
             digit = 0;
        }
        else if( digit == 3){
            c = 1;
            digit = 1;
        }
        else
            c = 0;
        res += digit + '0';
        --i;
    }
    
    
    while( j>= 0){
        digit = c + (B[j] - '0');
        if(digit == 2){
             c = 1;
             digit = 0;
        }
        else if( digit == 3){
            c = 1;
            digit = 1;
        }
        else
            c = 0;
        res += digit + '0';
        --j;
    }
    
    if(c)
        res += '1';
    //reverse the string
    i = 0; 
    j = res.size() - 1;
    char t;
    while(i < j){
        t = res[i];
        res[i] = res[j];
        res[j] = t;
        --j,++i;
    }
    return res;
}
