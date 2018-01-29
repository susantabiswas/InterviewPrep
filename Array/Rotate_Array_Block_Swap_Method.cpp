//Rotates the array elements by 'r'
/*rotate the array elements using block swap of elements */

#include<iostream>
using namespace std;

//swap block of array elements
//l1:lower index of first block,l1:lower index of second block
//n: no. of elements to swap
void swap(int arr[],int l1,int l2,int n)
{
	int temp=0;
	for (int i = 0; i < n; ++i)
	{
		temp=arr[l1+i];
		arr[l1+i]=arr[l2+i];
		arr[l2+i]=temp;
	}
}

//rotates the array elements by 'r'
/*divide the array into two parts one till rth element ,call it A ,call the second one B
ifA<B:divide B such that first part is equal to A .Then swap the that block with A.Recursively work on the rest of B
ifA>B:divide  A such that one block is equal to B .Then Swap that with B.Recursively work on the rest of A.*/
void rotate(int arr[],int r,int size)
{
	//when r=0 or when it is equal to the total size of array
	if(r==0 || r==size)
		return;
	//when half needs to be rotated
	if(r==size-r)
	{
		swap(arr,0,size-r,r);
		return;
	}
	//if A is shorter than B
	if(r<size-r)
	{
		swap(arr,0,size-r,r);
		rotate(arr,r,size-r);
	}
	//when B is shorter than A
	else
	{
		swap(arr,0,r,size-r);
		//total length of rem:n-(n-r),and length of B:n-r,then remaining A:n-2*(n-r)=2*r-n
		rotate(arr+size-r,2*r-size,r);
	}
}

//displays the array elements
void display(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={1, 2, 3, 4, 5, 6};
	int size=sizeof(arr)/sizeof(int);
	cout<<"Original Array:";
	display(arr,size);

	rotate(arr,3,size);
	display(arr,size);

	return 0;
}
