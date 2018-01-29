//Rabin Karp algo for pattern matching
//worst case:O(nm) when all the hash values are same as that of that of the pattern
//best case:O(n+m)

#include<iostream>
#include<cmath>
using namespace std;

//finds the pattern using rabin karp algo
void findPatternRabinKarp(string pat,string text){
	const int q=101;	//prime num req for modulo op
	int p=0,t=0,h;
	const int M=pat.size();
	const int N=text.size();
	const int base=256;		//256 for ascii chars

	//h=base^(size of pattern-1)
	h=pow(base,M-1);

	//compute the pattern hash value and the first window of text's
	for (int i = 0; i < M; ++i)
	 {
	 	p=(p*base + pat[i])%q;
	 	t=(t*base + text[i])%q;
	 }

	 int i=0;
	 //start finding the pattern
	 while(i<=N-M){
	 	//when hash values are similar then check for confirmation
	 	if(t==p){
	 		int j=0;
	 		while(j<M && pat[j]==text[j+i])
	 			++j;
	 		if(j==pat.size()){
	 			cout<<"Pattern found at:"<<i<<endl;
	 		}
	 	}
	 	//next we need to compute the hash values for
	 	//the rest substring
	 	if(i<N-M){
	 		t=(base*(t-h*text[i])+text[i+M])%q;
	 		//for ive values
	 		if(t<0)
	 			t=t+q;
	 	}
	 	++i;
	}
}

main(){
	string text = "aaaaaa";
	string pat = "aaa";
	findPatternRabinKarp(pat,text);
}
