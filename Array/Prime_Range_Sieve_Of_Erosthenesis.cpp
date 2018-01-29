//Given 'n' find out the prime numbers lying between 1 to n
#include<iostream>
#include<vector>
#include<list>
#include<cmath>
using namespace std;

template<class Y>
void disp(Y arr){
	class Y::iterator it;
	for(it = arr.begin();it!=arr.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}
//for checking if the num is prime or not
bool isPrime(int n){
	for(int i=2; i<=sqrt(n); i++)
		if(n%i ==0)
			return false;
	return true;
}

//checks for the multiples of a given number
void checkMultiples(vector<bool> &arr,int a,int n){
	for(int i = 2*a; i<= n;i+=a){
		arr[i] = false;
	}
}

//for finding the primes between 1 to n
/*
	Start from begining as we start finding primes ,mark their multiples as non primes
	,and skip them the next time we encounter them
*/
list<int> findPrime(int n){

	vector<bool> prime(n+1,true);
	list<int> prime_num;

	prime_num.push_back(2);

	prime[1] = false;
	for(int i = 3; i<=n ; i+=2){

		if(prime[i]){
			if(isPrime(i)){
				prime_num.push_back(i);
				checkMultiples(prime,i,n);
			}
			else
				prime[i] = false;
		}
	}
	return prime_num;
}

main(){
	int n = 30;

	list<int> primes = findPrime(n);
	disp(primes);
}
