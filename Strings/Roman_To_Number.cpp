/*Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
Example :

Input : "XIV"
Return : 14
Input : "XX"
Output : 20*/

/*
	If a character with smaller value lie before one with a larger value
	then the smaller character is subtracted from the immediate next bigger 
	valued character

	so for current character check
		if value(curr) < value (curr + 1):
			value = value - value(curr)
		else
			value += value(curr)
*/
int Solution::romanToInt(string A) {
    unordered_map< char, int> m;
    //give the values of the Roman Numerals
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    //for storing the value of the Roman Numerals
    int val = 0;
    int n = A.size();
    //for each character check its next character
    for(int i = 0; i<n; i++){
    	//if the priority of next character is lesser than subtract value
        if( i+1 < n && m[ A[i+1] ] > m[ A[i] ]){
            val = val - m[ A[i] ];
        }
        //if current priority is greater than or equal to the next then add value
        else{
            val += m[ A[i] ];
        }
   }
    return val;
}
