//Find the median of Merged array formed from two already sorted arrays
#include<iostream>
using namespace std;

//finds the median of the merged array
/*median is the mean of nth and n-1th element */
int Median(int arr1[],int size,int arr2[])
{	//i:for traversal of arr1,j:for traversal of arr2
	int i=0,j=0,k=0;
	int m1=0,m2=0;
	int prev=0;

	//merge till n/2th element
	for (k=0;k<2*size && i<size && j<size; ++k)
	{
		if(arr1[i]<=arr2[j])
		{
			prev=arr1[i];
				++i;
		}
		else
			if(arr1[i]>arr2[j])
			{
				prev=arr2[j];
					++j;
			}

		//store n-1/2th element's value
		if(k==size-1)
			m1=prev;
		//store n/2th element's value
		if(k==size)
			m2=prev;

	}
	if(m1 && m2)
		return (m1+m2)/2;

	//if arr2 finishes before taking the value of n/2th elements's value
	if(i<size)
		m2=arr1[i];
	//if arr1 finishes before taking the value of n/2th elements's value
	else if(j<size)
		m2=arr2[j];

	return (m1+m2)/2;
}

void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr1[] = {1, 12, 15, 26 };
    int arr2[] = {2, 13, 17, 30};

	//both the arrays have the same size
	int size1=sizeof(arr1)/sizeof(int);

	display(arr1,size1);
	display(arr2,size1);

	cout<<"\nMedian:"<<Median(arr1,size1,arr2);

	return 0;
}
