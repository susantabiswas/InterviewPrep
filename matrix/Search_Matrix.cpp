//search an element in a matrix of n X n.
/*every row and column is sorted in increasing order*/
#include<iostream>
using namespace std;

//searches an element in the matrix
int search(int arr[4][4],int n,int el)
{
   /*start from the last element of each row */
   int j=n-1;
   for(int i=0;i<n;i++)
   {
      j=n-1;
      //check if the last element is a match
      if(arr[i][j]==el)
         return 1;
      else if(el<arr[i][j])
      {
            for(int k=n-2;k>=0;--k)
            {
               if(arr[i][k]==el)
                  return 1;
            }

      }

   }
   return 0;
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
   int result=search(mat,4,32);
   if(result)
      cout<<"found\n";
   else
      cout<<"not found\n";
	return 0;
}
