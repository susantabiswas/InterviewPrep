
//Reverse an array using iterative method
/*Reverses any data type ,start with the beginning element and
the end element and replace them,increment start count and decrement end counter*/
#include<iostream>

using namespace std;

//reverses the array elements
template <class t>void reverse(t arr[],int size)
{
	t temp=0;
	for (int i = 0,j=size-1; i < j; ++i,--j)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

//displays the array elements
void display(int *arr,int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int size=sizeof(arr)/sizeof(int);
	display(arr,size);

	reverse(arr,size);
	display(arr,size);
	return 0;
}
