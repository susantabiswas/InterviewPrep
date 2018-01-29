//Rotates the array elements clockwise by 'r'
#include<iostream>
using namespace std;

/*rotates the array elements by shifting all the elements left 'r ' times
*/
void rotate(int arr[],int size,int r)
{
	int temp=0;
	int i=0;
	while(i<r)
	{
		temp=arr[0];
		for (int j = 0; j < size-1; ++j)
		{
			arr[j]=arr[j+1];
		}
		arr[size-1]=temp;
		++i;
	}
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
	int arr[]={1,2,3,4,5,6,7};
	int size=sizeof(arr)/sizeof(int);

	display(arr,size);

	rotate(arr,size,2);
	display(arr,size);
	return 0;
}
