//Reverse an array using recursion
/*Reverses any data type ,start with the beginning element and
the end element and replace them,increment start count and decrement end counter*/
#include<iostream>

using namespace std;

//reverses the array elements
template <class t>void reverse(t arr[],int l,int h)
{
	t temp=0;
	if(l<h)
	{
		temp=arr[l];
		arr[l]=arr[h];
		arr[h]=temp;
		reverse(arr,l+1,h-1);
	}
}

//displays the array elements
template <class t>void display(t *arr,int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	char arr[]="string";
	int size=sizeof(arr)/sizeof(char);

	display(arr,size);

	reverse(arr,0,size-1);
	display(arr,size);
	return 0;
}
