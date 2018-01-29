//Given a string ,print all its permutations
/*
	Works only for string without any duplicates
	TC: O(n* n!) since there can be n! possible pmt and for each 
	pmt it takes
	O(n) for printing it since all the pmt are leaf nodes
*/
#include<iostream>
using namespace std;

//for swapping string chars
void swap(string &str, int a, int b){
	char c = str[a];
	str[a] = str[b];
	str[b] = c;
}

//prints the permutation of the given string
/*
	we make a recursive tree where the the leaf nodes are the pmts
	for each call swap a char with another
*/
void printPermutation(string str, int l, int r){
	//when leaf node is reached
	if(l == r)
		cout<<str<<endl;
	else{
		for (int i = l; i <=r; ++i)
		{
			//swap chars for call
			swap(str,l,i);
			printPermutation(str,l+1,r);
			//undo the swap for further calls
			swap(str,l,i);

		}
	}
}

int main(){
	string str = "AABC";
	printPermutation(str,0,str.size()-1);
	return 0;
}
