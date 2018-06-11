/*
Implement pow(A, B) % C.

In other words, given A, B and C, 
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2
*/

int Solution::Mod(int A, int B, int C) {
    
    if( A == 0)
        return 0;
    if( B == 0)
        return 1;
    long long int res = Mod(A,B/2,C);
    
    //even power
    if( B % 2 == 0)
        res = ( res%C * res%C )% C;
    else{
        //when neg power
        if(B < 0)
            res = (( res%C * res%C)/A) % C;
        else
            res = ( res%C * res%C * A) % C;
    }
    
    //if the ans becomes negative
    if(res < 0)
        return ( res + C) % C;
    else
        return res;
}
