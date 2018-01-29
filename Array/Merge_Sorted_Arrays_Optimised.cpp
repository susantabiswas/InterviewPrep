//Merge two given sorted arrays ,one with size m+n having 'm' elements and other with size 'n' having 'n' elements.
//Merged array should be sorted
#include<iostream>
#define NA -1						//Assuming NA is -1
using namespace std;

//Moves all the non-blank(m) elements towards the end of the array
int Move(int arr[],int size)
{
	int i=size-1;
	int j=size-1;
	for (i ; i>=0; --i)
	{
		if(arr[i]!=NA)
		{
			arr[j--]=arr[i];
		}
	}
	return j+1;
}

//Merges the two array into the first array
void Merge(int arr1[],int arr2[],int size1,int size2)
{
	int j=0;
	int k=Move(arr1,size1);
	int i=0;
	//compare elements form both arrays
	for (i = 0; i < size1 && k<size1 && j<size2; ++i)
	{
		if(arr1[k]<arr2[j])
		{
			arr1[i]=arr1[k++];
		}
		else
		{
			arr1[i]=arr2[j++];
		}
	}

	//if m elements have already been used and some elements from arr2 remains
	if(j<size2)
		arr1[i++]=arr1[j++];
}

int main()
{
	int arr1[]={2, 8, NA, NA, NA, 13, NA, 15, 20};
	int arr2[] = {-25, -17, -9,8, 20};
	int size1=sizeof(arr1)/sizeof(int);
	int size2=sizeof(arr2)/sizeof(int);

	Merge(arr1,arr2,size1,size2);
	cout<<"Merged array:\n";
	for (int i = 0; i < size1; ++i)
	{
		cout<<arr1[i]<<" ";
	}


	return 0;
}
