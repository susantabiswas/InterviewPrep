//Rotates the array elements clockwise by 'r' using juggling algorithm
#include<iostream>
using namespace std;

//finds the gcd
int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

//displays the array elements
void display(int arr[],int size)
{
	cout<<endl<<"Contents:  ";
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

/*rotates the array elements in blocks
Number of elements in a block is equal to GCD of 'r' and 'size'.No. of blocks =size/gcd(size,r)
move sequentially the elements of one block to its previous block at that position from where the 
element was shifted
*/
void rotate(int arr[],int size,int r)
{
	int g=gcd(size,r);
	int i=0,j=0,k=0;
	int temp=0;

	for (int i = 0; i < g; ++i)
	{
		 j=i;
		 temp=arr[i];
		 while(1)
		 {
		 	k=j+r;
		 	if(k>=size)
				k=k-size;
			if(k==i)
				break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}

}



int main()
{
	int arr[]={1,2,3,4,5,6};
	int size=sizeof(arr)/sizeof(int);

	display(arr,size);
	cout<<"******************\n";
	rotate(arr,size,2);
	display(arr,size);
	return 0;
}
