////Given a string ,print all its permutations using next_permutation() of STL
/*
	Works only for string with duplicates also
	TC: O(n*n-1 + nlogn)
	next_permutation() takes O(n) :it finds and modifies the next 
	lexographically larger string else if not possible then returns 
	false we sort the string in incresing order so that it is 
	lexographically smallest then apply next_permutation till possible
*/
#include<iostream>
#include<algorithm>
using namespace std;

//for swapping string chars
void swap(string &str, int a, int b){
	char c = str[a];
	str[a] = str[b];
	str[b] = c;
}

//prints the permutation of the given string
/*
*/
void printPermutation(string str, int l, int r){
	sort(str.begin(),str.end());
	cout<<str<<endl;
	while(next_permutation( str.begin(),str.end() ) ){
		cout<<str<<endl;
	}

}

int main(){
	string str = "AABC";
	printPermutation(str,0,str.size()-1);
	return 0;
}
