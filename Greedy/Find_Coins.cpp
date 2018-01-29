//given a value .Find the min number of indian rupees/coins required for making
//up that value.There is infinite supply of each denomination
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//finds the no. of coins/ notes required for making up the value
int denominationsRequired( vector<int> &arr, int val){
	int c = 0;
	//sort the denominations in descending order
	sort(arr.rbegin(), arr.rend());
	int i = 0;
	while(val > 0){
		//while current denomination can make up some part of the value
		if(arr[i] <= val){
			c = c + val/arr[i];
			val = val%arr[i];
		}
		i++;
	}
	return c;
}

int main(){
	int val = 93;
	vector<int> arr = {1000,500,100,50,20,10,5,2,1};
	cout << denominationsRequired(arr, val);
}
