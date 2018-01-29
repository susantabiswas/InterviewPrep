//Merge two given sorted arrays ,one with size m+n having 'm' elements and other with size 'n' having 'n' elements.
//Merged array should be sorted
#include<iostream>
#define NA -1 			//Assuming NA is -1
using namespace std;

//Merges the two array into the first array
/*Start with the first element of arr1 and arr2.If the arr1 element is NA then we search for the first non NA element and compare with arr2
the smaller of the two gets its position in the arr1 and other gets the position in arr2 where it belongs.*/
void Merge(int arr1[],int arr2[],int size1,int size2)
{
	//i:for traversal in arr1 ,j:for traversal in arr2
	int i=0,j=0,in=0,k=0;
	int swap=0;
	for (in = 0; in < size1 && i<size1; ++in)
	{	//if element is NA then traverse till first non NA element in arr1
		if(arr1[in]==NA)
		{
			while(arr1[i]==NA)
				++i;
		}
		//compare the first element of arr2 with ith element of array 1
	    if(arr1[i]<arr2[j])
		{
			arr1[in]=arr1[i];
			++i;
		}
		//if element of array1 is bigger than arr2 element,then save its value at the correct position in arr2
		else if(arr1[i]>arr2[j])
		{
			swap=arr1[i];
			arr1[in]=arr2[j];
			arr2[j]=swap;

			swap=arr2[0];
			k=1;
			while(swap>arr2[k] && k<size2)
			{
				arr2[k-1]=arr2[k];
				++k;
			}
			arr2[k-1]=swap;

			++i;
		}
	}

	//insert the remaining elements of arr2 in arr1
	j=0;
	while(in<size1)
		arr1[in++]=arr2[j++];
}

int main()
{
	int arr1[]={2, 8, NA, NA, NA, 13, NA, 15, 20};
	int arr2[] = {-25, -17, -9, -2};
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
