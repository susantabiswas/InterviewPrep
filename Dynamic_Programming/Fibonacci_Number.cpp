//Print the nth fibonacci number
#include<iostream>
#include<vector>
using namespace std;
#define nil -9999999

//Top down approach: Memoization
int findNthFibonacciMem(int n,vector<int> &lookup){
	//check if the answer is there in lookup table or not
	if(lookup[n] == nil){
		//store the value in lookup for future use
		if(n <= 1)
			lookup[n] = n;
		else
			lookup[n] = findNthFibonacciMem(n-1,lookup) + findNthFibonacciMem(n-2,lookup);
	}
	return lookup[n];
}

//bottom up approach:Tabulation
int findNthFibonacciTab(int n){
	vector<int> lookup(n+1);
	//first two terms of fibonacci series
	lookup[0] = 0;
	lookup[1] = 1;

	for(int i = 2; i<=n; i++){
		lookup[i] = lookup[i-1] + lookup[i-2];
	}
	return lookup[n];
}

//prints the nth fibonacci number
int nthFibonacci(int n){
	//for memoization
	vector<int> lookup(n+1,nil);
	return findNthFibonacciMem(n,lookup);
}

int main(){
	int n = 5;
	cout<< nthFibonacci(n);
	cout<<endl<<findNthFibonacciTab(n);
}
