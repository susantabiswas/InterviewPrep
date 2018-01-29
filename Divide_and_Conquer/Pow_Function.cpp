//implement pow(x,n)
#include<iostream>
using namespace std;

//computes x^n
//TC: O(n): T(n) = T(n/2) + T(n/2) +O(1)
int computePower(int x, int n){
	if(n == 2)
		return x*x;
	if(n == 1)
		return x;
	if(n == 0)
		return 1;
	return computePower(x,n/2)*computePower(x,n- n/2);
}

//Tc: O(logn): T(n) = T(n/2) + O(1)
//here we only divide the power once not twice like the previous one
int computePower1(int x, int n){
	if(n == 0)
		return 1;
	int t = computePower1(x,n/2);

	//check if the power is even
	if( n%2 == 0)
		return t*t;
	//when it is positive and has odd power
	if(n > 0)
		return t*t*x;
	//when it is a negative power
	else
		return t*t/x;
}

int main(){
	int x = 2;
	int n = 10;
	cout<< computePower(x,n);
	x = 2;
	n = -2;
	cout<<endl;
	cout<<computePower1(x,n);
}
