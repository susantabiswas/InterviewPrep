/*Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. */

int Solution::atoi(const string &A) {
    //first scan the string and seprate out the digits if any
    string str;
    bool neg = false;
    int num = 0;
    int i = 0;
    //ignore spaces 
    while( i < A.size() && A[i] == ' ')
        ++i;
    //check if the current char is digit or not
    //if it is garbage then return
    if( isalpha(A[i]))
        return 0;
    
    //check if the number is negative or not
    if(A[i] == '-'){
        neg = true;
        ++i;
    }
    else if( A[i] == '+'){
        neg = false;
        ++i;
    }
   
    //take out the digits
    //if the number is +ve
    if( !neg ){  
        while( i < A.size() && isdigit(A[i])){
            //for checking overflow
            if(num > INT_MAX/10)
                return INT_MAX;
            num = num*10;
            //for checking overflow
            if( num >0 && num > INT_MAX - A[i])
                return INT_MAX;
            num = num + (A[i] - '0');
            ++i;
        }
    }
    else{		//if the number is negative
         while( i < A.size() && isdigit(A[i])){
             //for checking underflow
            if( num < (INT_MIN/10)){
                return INT_MIN;
            }
            num = num*10;
            
            //for checking underflow
            if( num <0 && num < INT_MIN + A[i])
                return INT_MIN;
            num = num - (A[i] - '0');
            ++i;
        }
    }
    
    return num;
}
