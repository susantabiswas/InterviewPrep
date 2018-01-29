//Given a boolean matrix mat[M][N] of size M X N, modify it such that
//if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.
#include<iostream>
using namespace std;

//modifies the matrix
void modify(bool arr[3][4],int r,int c)
{ 
	//for storing the indices where the value is true
	bool row[r];
	bool col[c];
	for(int i=0;i<r;i++)
		row[i]=false;
	for(int i=0;i<r;i++)
		col[i]=false;

	//check for true value in rows and columns
	//and save their indices
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(arr[i][j]==true)
			{
				row[i]=true;
				col[j]=true;
			}
		}
	}
	
	//modify the ith row
	for (int i = 0; i < r; ++i)
		if(row[i]==true)
			{
			for (int j = 0; j < c; ++j)
				arr[i][j]=true;
			}

	//modify the jth column
	for (int i = 0; i < c; ++i)
		if(col[i]==true)
			{
				for (int j = 0; j < c; ++j)
				arr[j][i]=true;
			}
}

//displays the elements of matrix
void display(int r,int c,bool arr[3][4])
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	bool mat[3][4] = { {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };
	cout<<"Contents:\n";
 	display(3,4,mat);
 	modify(mat,3,4);
 	cout<<"Contents after Modification:\n";
 	display(3,4,mat);
	return 0;
}
