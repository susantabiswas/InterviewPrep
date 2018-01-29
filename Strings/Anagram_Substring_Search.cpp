//find the given pattern and also its anagrams in the given text
//i.e all its possible comibinations eg:text:abdssdab and pattern is abds then output
//will be pattern at 0 and 4
#include<iostream>
#include<vector>
using namespace std;

//finds the given pattern and also its possible anagrams in the given text
/*
	We use rabin karp logic just we change the hash value in this case
	1) O(mn) in worst case: we sum up the chars ascii values in the hash values
	   and when the hash values match then only we search .When the hash value matches
	   for all the substrings then the worst case occurs
	2) O(n): we keep count of the occurrences of the chracters of the pattern and the text window
	   every time we shift the window we decrease the count value of the previous char and inccrement
	   count value of the next char in the window
*/
void findAnagramPatterns(string pat,string text){

	const int M=pat.size();
	const int N=text.size();
	const int ASIZE=256;	//size of ascii chars
	vector<char> t_occur(ASIZE);	//for storing occurrences of text window
	vector<char> p_occur(ASIZE);	//for storing occurrences of pattern

	//make the first window of the text and pattern ready
	for (int i = 0; i < M; ++i)
	{
		t_occur[text[i]]++;
		p_occur[pat[i]]++;
	}

	int i=0,j=0;
	while(i<=N-M){
		j=0;
		//check the current window
		while(j<M){
			if(t_occur[pat[j]]!=p_occur[pat[j]]){
				break;
			}
			++j;
		}

		if(j==M){
			cout<<"Occurence found at: "<<i<<endl;
		}

		//make the next window ready
		t_occur[text[i]]--;
		t_occur[text[i+M]]++;
		i++;
	}

}

main(){
	string text="BACDGABCDA";
	string pat="ABCD";
	findAnagramPatterns(pat,text);
}
