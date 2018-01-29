//Print the elements of a matrix in spiral form

#include<iostream>
using namespace std;

//prints the elements in spiral form
void spiralDisplay(int arr[4][4],int n)
{
   cout<<"Spiral Display:\n";
  int i=0;
  int j=n-1;
  for (int i = 0; i < n; ++i)
  {
    //when the row is even,then go towards right
    if(i%2==0)
      for (int j = 0; j < n; ++j)
         cout<<arr[i][j]<<" ";

    //when row is odd,go towards left
    else
      for (j=n-1; j >=0; --j)
         cout<<arr[i][j]<<" ";
   }
}

//displays the matrix
void display(int n,int arr[4][4])
{cout<<"Matrix\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };

   display(4,mat);

   spiralDisplay(mat,4);
	return 0;
}
