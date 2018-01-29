//Given a Number X and 'n' die each having 'm' faces.In how many ways can we
//get X
#include<iostream>
#include<vector>
using namespace std;

int findWays(int m, int n, int x){
	//when we get the number
	if(x == 0 && n == 0)
		return 1;
	//when the die are still left but the value is too small
	if(x <= 0 && n >= 1 )
		return 0;
	//when the value and die both are not enough
   if(x <= 0 || n <= 0)
		return 0;
	//when x is still left
	if(x > 0 && n <= 0)
		return 0;
	int c = 0;
	/*
		try with each possible value that the nth dice can give and recurse
	*/
	for (int i = 1; i <= m; ++i)
	{
		c += findWays(m, n-1, x-i);
	}
	return c;
}

//Tc:????
int findWaysMem(int m, int n, int x, vector< vector<int> > lookup){
	//when we get the number
	if(x == 0 && n == 0)
		return 1;
	if(x <= 0 && n >= 1 )
		return 0;
   if(x <= 0 || n <= 0)
		return 0;
	//when x is still left
	if(x > 0 && n <= 0)
		return 0;

	if(lookup[n][x] != -1)
		return lookup[n][x];
	int c = 0;
	for (int i = 1; i <= m; ++i)
	{
		c += findWays(m, n-1, x-i);
	}
	return lookup[n][x] = c;
}
int main(){

	//no. of faces
	int m = 6;
	//no. of dice
	int n = 3;
	//sum
	int x = 8;
	cout << findWays(4,3,5);
	//for dp
	vector< vector<int> > lookup(n+1, vector<int>(x+1,-1));
	cout<<endl<<findWaysMem(4,3,5,lookup);
	return 0;
}
