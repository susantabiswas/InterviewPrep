//Search an element in a sorted array which has been rotated at some pivot unknown beforehand.

#include<iostream>
using namespace std;

//for doing binary search
bool binarySearch(int arr[],int l,int h,int element)
{
	if(l==h)
	{
		if(arr[l]==element)
			return true;
	}
	if(l<h)
	{
		int mid=(l+h)/2;
		if(arr[mid]==element)
			return true;
		if(arr[mid]<element)
			binarySearch(arr,l,mid-1,element);
		else
			binarySearch(arr,mid+1,h,element);
	}
}

//for searching the element
/*First find the pivot element ,the element after pivot is smaller than  it*/
bool Search(int arr[],int size,int element)
{
	bool result=0;
	int pivot=0;
	//search for pivot
	for(int i=0;i<size-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			pivot=i;
			break;
		}
	}
	//if the element is equal to the pivot
	if(arr[pivot]==element)
		return true;
	//else do binary search on both the sorted halves
	if(arr[pivot]<element)
		return binarySearch(arr,0,pivot-1,element);
	else
		return binarySearch(arr,pivot+1,size-1,element);
}

int main()
{
	int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
	int size=sizeof(arr)/sizeof(int);

	bool result=Search(arr,size,1);

	if(result)
		cout<<"Element found\n";
	else
		cout<<"Element not found\n";
	return 0;
}
