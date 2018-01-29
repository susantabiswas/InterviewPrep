//Given a matrix of nXm and 'k'.Print the kth element
#include<iostream>
#include<vector>
using namespace std;

//prints the kth element in spiral order traversal
//n:no. of rows ,m: no. of columns,k : position of element to find(1 based indexing)
/*
	Check for the edges if the element is there or not ,if not then pass the submatrix
	recursively.There are 4 edges: upper ,right,bottom,left
*/
int printKthElement(vector<vector<int> > arr,int x,int y,int n,int m,int k){

	if(n<0 || m<0)
		return -1;
	//when the element is on the upper row
	if(k<=m)
		return arr[x][k-1+y];
	else if(k<= m + n-1)
		return arr[k-m +x][m-1 +y];
	else if(k<= m+n-1+m-1)
		return arr[n-1 +x][(m-1)-(k-(m+n-1)) +y];
	else if(k<= m+n-1 +m-1 +n-2)
		return arr[(n-1)-(k-(m+n-1+m-1)) +x][y];
	else
		return printKthElement(arr,x+1,y+1,n-2,m-2,k-(2*m+2*n-4));

}

main(){
	vector< vector<int> > arr = {
									{1,2,3,4},
									{5,6,7,8},
									{9,10,11,12},
									{13,14,15,16},
									{17,18,19,20}
								};
	int k =16;
	cout<< printKthElement(arr,0,0,5,4,k);
}
