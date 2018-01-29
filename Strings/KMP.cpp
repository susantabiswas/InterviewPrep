#include<iostream>
#include<vector>
using namespace std;

//KMP algorithm
/*
	We precompute the array containing the largest proper prefix such that it is equal to the
	proper suffix for the pattern .
	Then using that we try to know in case of mismatch how much to shift the pattern array to
	match.Since upto the elements before the mismatch both the pattern and text chars were matching
	so we should find the largest matching prefix of pattern which matches with the suffix of the
	text before the mismatch .So in the array also we have maintained the count of the largest
	matching suffix and prefix of the pattern so we can know how much of the prefix will be
	matching the suffix of the pattern and since the chars till mismatch will  be same for
	pattern and text we shift the pattern array by that much amount

	T:========|=====================

	P:==\=====|==          
	P:      ==\=========
	here | denotes the mismatch and \ denotes the index till which the prefix is same
	as the suffix  so we shift by that much amount ,anything lesser than that shift will
	actually be useless as the chars will be different in text and pattern.

*/

//for computing the lps(largest proper suffix)
void computeLPS(string pat,vector<int> &lps){
	int i,j;
	i=1;
	j=0;

	while(i<pat.size()){
		//when both the chars are equal
		if(pat[i]==pat[j]){
			++j;
			lps[i]=j;
			++i;
		}
		//when there is a mismatch in the chars we move j backwards
		else{
			if(j!=0)
				j=lps[j-1];
			else{
				lps[i]=0;
				++i;
			}
		}
	}

}

//KMP algo:shows where the matchings occur in the text
void findPatternKMP(string pat,string text){
	
	//for precomputation of lps
	vector<int> lps(pat.size());
	computeLPS(pat,lps);

	int i=0,j=0;
	while(i<text.size()){

		if(text[i]==pat[j]){
			++i;
			++j;
			if(j==pat.size()){
				cout<<"matching found at:"<<i-pat.size()<<endl;
				if(j!=0)
					j=lps[j-1];
				else if(j==0){
					++i;
				}
			}
		}
		//mismatch has occurred
		else{
			//look for the largest prefix length
			if(j!=0)
				j=lps[j-1];
			else if(j==0){
				++i;
			}
		}
	}
}

main(){
	string text = "aaaaaa";
    string pat = "aaa";
	findPatternKMP(pat,text);
}
