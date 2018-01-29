//given rope with length 'n'.Find how many cuts should be made so that the product of
//the cuts is maximum.Atleast one cut has to be made and min length is 2
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//finds the cuts so that product is max
/*
	Just like the rod cutting problem for each length try all possible lengths for it
*/
int maxCutPro(int n, bool first){
	if(n == 1 || n == 0)
		return 1;
	
	int pro = 0;

	int max = numeric_limits<int>::min();
	//since atleast one cut has to be made so first time the cut length can't be equal to
	//length of the rope,but after  making the first cut we can use the entire length as the remaining
	//cut
	//eg: length :5
	//say first cut was :1,then we can return 4 for the remaining length 4
	if(first){
		for (int i = 1; i < n; ++i)
		{
			pro = i * maxCutPro(n-i,false);
			if(pro > max){
				max = pro;
			}
		}
	}
	else{
		for (int i = 1; i <= n; ++i)
		{
			pro = i * maxCutPro(n-i,false);
			if(pro > max){
				max = pro;
			}
		}
	}

	return max;
}

//Tc:O(n^2)
//finds the cuts so that product is max
int maxCutProMem(int n, bool first, vector<int> &lookup){
	if(n == 1 || n == 0)
		return 1;
	if(lookup[n] != -1)
		return lookup[n];
	int pro = 0;

	int max = numeric_limits<int>::min();
	if(first){
		for (int i = 1; i < n; ++i)
		{
			pro = i * maxCutProMem(n-i,false,lookup);
			if(pro > max){
				max = pro;
			}
		}
	}
	else{
		for (int i = 1; i <= n; ++i)
		{
			pro = i * maxCutProMem(n-i,false,lookup);
			if(pro > max){
				max = pro;
			}
		}
	}

	return lookup[n] = max;
}

int main(){
	int n = 16;
	bool first = true;
	//for dp
	vector< int> lookup(n+1,-1);
	cout << maxCutPro(n, first);
	cout <<endl << maxCutProMem(n,first, lookup);
}
