//Print a given n X n 2D matrix in Spiral form
#include<iostream>
#include<vector>
using namespace std;

//prints the matrix in spiral form
void printSprial(vector< vector<int> > &arr,int n){
	bool right = true;
	bool left = false;
	bool up =false;
	bool down = false;
	int col_start = 0,col_end = n-1;
	int row_start = 0,row_end = n-1;
	int k = 0;

	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<"  ";
	}
	cout<<endl;}
	cout<<"\nSpiral Order:\n";
	while(row_start<=row_end && col_start<=col_end){

		if(right){

			for(int i = col_start;i<=col_end;i++)
				cout<<arr[row_start][i]<<" ";
			right = false;
			down = true;
			row_start++;
		}
		else if(down){
			for(int i = row_start;i<=row_end;i++)
				cout<<arr[i][col_end]<<" ";
			down = false;
			left = true;
			col_end--;

		}
		else if(left){
			for(int i = col_end;i>=col_start;i--)
				cout<<arr[row_end][i]<<" ";
			left = false;
			up = true;
			row_end--;
		}
		else if(up){
			for(int i = row_end;i>=row_start;i--)
				cout<<arr[i][col_start]<<" ";

			up = false;
			right = true;
			col_start++;
		}

	//	k++;
	}
}

main(){
	vector< vector<int> > arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	printSprial(arr,4);
}
