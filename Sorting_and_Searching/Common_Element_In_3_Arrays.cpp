//given 3 sorted arrays.Find all the common elements
/*
	let a,b,c be the indices of the respec. arrays then:
	if a == b == c
		print them and increment each
	if a < b
		++a
	else if b < c:
		++b
	else
		++c
*/
#include<iostream>
#include<vector>
using namespace std;

//prints the common elements
void printCommonElements(vector<int> &a1,vector<int> &a2, vector<int> &a3){
	int a = 0,b = 0, c = 0;
	while(a < a1.size() && b < a2.size() && c < a3.size()){
		if( a1[a] == a2[b] && a1[a] == a3[c]){
			cout<<a1[a]<<" ";
			a++;
			b++;
			c++;
		}
		else if(a1[a] < a2[b])
			++a;
		else if(a2[b] < a3[c])
			++b;
		else
			++c;
	}
}

int main(){
	vector<int> a1 = {1, 5, 10, 20, 40, 80};
	vector<int> a2 = {6, 7, 20, 80, 100};
	vector<int> a3 = {3, 4, 15, 20, 30, 70, 80, 120};
	printCommonElements(a1,a2,a3);
	return 0;
}
