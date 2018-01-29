//Find the median of Merged array formed from two already sorted arrays
#include<iostream>
using namespace std;

//returns median of an array
int getMedian(int arr[],int size)
{
	if(size%2==0)
		return (arr[size/2-1]+arr[size/2])/2;
	else
		return arr[size/2];
}

//finds the median of the merged array
/*median is the mean of nth and n-1th element */
int Median(int arr1[],int arr2[],int size)
{
	if(size<=0)
		return -1;
	if(size==1)
		return (arr1[0]+arr2[0])/2;
	if(size==2)
		return (max(arr1[0],arr2[0])+min(arr1[1],arr1[1]))/2;

	int m1=getMedian(arr1,size);
	int m2=getMedian(arr2,size);

	if(m1==m2)
		return m2;

	//if m1<m2 then median lies in arr1[m1,...size-1] and arr2[0...size/2-1]
	if(m1<m2)
	{
		//if no. of elements is even
		if(size%2==0)
		{
			return Median(arr1+size/2-1,arr2,size-size/2+1);
		}
		//if no. of elements is odd
		else
		{
			return Median(arr1+size/2,arr2,size/2+1);
		}
	}
	//if m1>m2 then median lies in arr2[m1,...size-1] and arr1[0...size/2-1]
	else
	{
		//if no. of elements is even
		if(size%2==0)
		{
			return Median(arr1,arr2+size/2-1,size-size/2+1);
		}
		//if no. of elements is odd
		else
		{
			return Median(arr1,arr2+size/2,size/2+1);
		}

	}
}



void display(int arr[],int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr1[] = {1, 2, 3, 6};
	int arr2[] = {4, 6, 8, 10};

	//both the arrays have the same size
	int size1=sizeof(arr1)/sizeof(int);

	display(arr1,size1);
	display(arr2,size1);

	cout<<"\nMedian:"<<Median(arr1,arr2,size1);

	return 0;
}
