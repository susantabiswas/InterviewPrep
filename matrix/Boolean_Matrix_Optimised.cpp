//Given a boolean matrix mat[M][N] of size M X N, modify it such that
//if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.
/*Space optimised solution*/
#include<iostream>
using namespace std;

//modifies the matrix
void modify(bool arr[3][4],int r,int c)
{ //for knowing whether the first row and column needs to be made true ,as they are to be used for storing indices
	int rowFlag=0;
	int colFlag=0;
	/*here the first row and column of matrix will be used for storing the indices of columns and rows  respectively*/
	//check for the first row
	for (int i = 0; i < c; ++i)
	{
		if(arr[0][i]==true)
		{
			rowFlag=1;
			break;
		}
	}
	//check for the first row
	for (int i = 0; i < r; ++i)
	{
		if(arr[i][0]==true)
		{
			colFlag=1;
			break;
		}
	}

	//check for true value in rows and columns from 2nd row and column
	//and save their indices
	for (int i = 1; i < r; ++i)
	{
		for (int j = 1; j < c; ++j)
		{
			if(arr[i][j]==true)
			{
			//save indices of columns in first row and indices of rows in first column
			//since first row already might contain the indices of columns having true value,same goes for first column
				arr[0][j]=true;		//1st row
				arr[i][0]=true;		//1st column
			}
		}
	}
//modify the ith row
	for (int i = 1; i < r; ++i)
	{
		if(arr[i][0]==true)
		{
			for (int j = 1; j < c; ++j)
				arr[i][j]=true;
		}
	}
//modify the jth column
	for (int j = 1; j < c; ++j)
		if(arr[0][j]==true)
		{
			for (int i = 1; i < r; ++i)
				arr[i][j]=true;
		}

//make first row and first column true based on flags
	if(rowFlag)
		for (int i = 0; i < c; ++i)
			arr[0][i]=true;

	if(colFlag)
		for (int i = 0; i < r; ++i)
			arr[i][0]=true;

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
