//Rotates the array by 'r'
#include<iostream>
using namespace std;

//reverses the array elements
template <class t>void reverse(t arr[],int l,int h)
{
	t temp=0;
	for (int i = l,j=h; i < j; ++i,--j)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

//rotates the array elements
/*reverse till rth element
then reverse the rest,finally reverse the total array*/
void rotate(int arr[],int size,int r)
{
	//reverse elements till rth element
	reverse(arr,0,r-1);

	//reverse the rest
	reverse(arr,r,size-1);

	//now reverse the total array
	reverse(arr,0,size-1);
}

//displays the array elements
void display(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={1,2,3,4,5,6};
	int size=sizeof(arr)/sizeof(int);

	display(arr,size);

	rotate(arr,size,2);
	display(arr,size);
	return 0;
}
