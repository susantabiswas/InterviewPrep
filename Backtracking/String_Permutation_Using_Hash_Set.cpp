//Given a string ,print all its permutations
/*
	Works for string  with duplicates also
	TC: O(n* n!) since there can be n! possible pmt and for each pmt 
	it takes O(n) for printing it since all the pmt are leaf nodes
	Uses hash map or set for storing the unique strings and 
	prevents duplication
*/
#include<iostream>
#include<map>
#include<set>
using namespace std;

//for swapping string chars
void swap(string &str, int a, int b){
	char c = str[a];
	str[a] = str[b];
	str[b] = c;
}

//prints the permutation of the given string using hash map
/*
	we make a recursive tree where the the leaf nodes are the pmts
	for each call swap a char with another
*/
void printPermutationHash(string &str, int l, int r, map<string,int> &h){
	//when leaf node is reached
	if(l == r){
		//print only when the string doesn't exits in the hash map
		if(h.find(str) == h.end()){
			cout<<str<<endl;
			h[str] = 1;
		}
	}
	else{
		for (int i = l; i <=r; ++i)
		{
			//swap chars for call
			swap(str,l,i);
			printPermutationHash(str,l+1,r,h);
			//undo the swap for further calls
			swap(str,l,i);

		}
	}
}

//prints the permutation of the given string using set
/*
	we make a recursive tree where the the leaf nodes are the pmts
	for each call swap a char with another
*/
void printPermutationSet(string &str, int l, int r, set<string> &s){
	//when leaf node is reached
	if(l == r){
		//print only when the string doesn't exits in the set
		if(s.find(str) == s.end()){
			cout<<str<<endl;
			s.insert(str);
		}
	}
	else{
		for (int i = l; i <=r; ++i)
		{
			//swap chars for call
			swap(str,l,i);
			printPermutationSet(str,l+1,r,s);
			//undo the swap for further calls
			swap(str,l,i);

		}
	}
}

int main(){
	string str = "AABC";
	map<string,int> h;
	set<string> s;
	printPermutationHash(str,0,str.size()-1,h);
	cout<<endl;
	printPermutationSet(str,0,str.size()-1,s);
	return 0;
}
