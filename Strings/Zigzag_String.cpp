/*Zigzag StringBookmark Suggest Edit
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"*/


/*
	ini: j = 0 and direction = DOWN
	make a vector of string s[row]
	start traversing the given string:
		go down till you reach row-1
		1. At each step add the current char to that row
		2. when we reach row-1:
				then make direction as UP and --j
			else
				++j


		go up till you reach 0: 
		1. At each step add the current char to that row
		2. when we reach 0:
				then make direction as DOWN and ++j
			else
				--j

*/

string Solution::convert(string A, int B) {
    bool top = false;
    int j = 0;
    int i = 0; 
    
    //when the string doesn't req. more than 1 row 
    if(B <= 1)
        return A;
    
    //make a vector of different rows
    vector<string> s( B );
    string str;

    while(i < A.size()){
        //if going down
        if( !top ){
            s[j].push_back( A[i] );
            //if currently at the bottom
            //change direction and start moving up
            if( j == B-1 ){
                top = true;
                --j;
            }
            else
                ++j;
        }//going up
        else{
            s[j].push_back( A[i] );
            //when at the top row,make the direction as down and
            //start going down
            if( j == 0 ){
                top = false;
                ++j;
            }
            else
                --j;
        }

        ++i;
    }
    //copy string row-wise 
    for(int i = 0; i<B; i++){
        for(int j = 0; j<s[i].size(); j++)
            str += s[i][j];
    }
    return str;
}
