//Given a Matrix of NXN .Rotate it by 90 degrees
#include<iostream>
#include<vector>
using namespace std;

template <class T>
void disp(T arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		for(int j =0; j<arr.size(); j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

//rotates the matrix by 90 degrees
/*
	Work on on the elements of the edges only.Swapping one by one the values
*/
void rotateMatrix( vector< vector<int> > &arr,int x,int y,int n){
	int t1 = 0,t2 = 0;
	if(n<1)
		return;

	for(int i = 0; i<n-1; i++){

		//store the 2nd value
		t1 = arr[i+x][y+ n-1];
		//swap the second value with the first one
		arr[i+x][y+ n-1] = arr[x][y+i];

		//store the 3rd value
		t2 = arr[x+n-1][y +(n-1) -i];
		//swap the value of 3rd with 2nd
		arr[x +n-1][y +(n-1)-i] = t1;

		//store the value of 4th value
		t1 = arr[x+(n-1)-i][y];
		//swap the 4th value with the 3rd
		arr[x+(n-1)-i][y] = t2;

		//swap the value of 1st with 4th
		arr[x][y+ i] = t1;

		rotateMatrix(arr,x+1,y+1,n-2);
	}
}

main(){
	vector< vector<int> > arr = {
									{1,2,3,4},
									{5,6,7,8},
									{9,10,11,12},
									{13,14,15,16},
								};
	cout<<"Original:\n";
	disp(arr);
	rotateMatrix(arr,0,0,4);
	cout<<"\n\nAfter rotation:\n";
	disp(arr);
}
