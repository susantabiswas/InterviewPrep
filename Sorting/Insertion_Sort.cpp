//Insertion Sort using Array
#include<iostream>
using namespace std;


//For performing Insertion sort
void InsertionSort(int *arr,int size)
{	//In Insertion Sort we consider the list to be composed of sorted and unsorted portion
	//we move first element from unsorted portion to the sorted portion
	int element=0;
	int j=0;
	for (int i = 0; i <=size-1; ++i)
	{
		//i is the index of first element of unsorted list
		element=arr[i];
		j=i;
		//move in the sorted list till the correct position
		while(j>0 && arr[j-1]>element)
		{
			arr[j]=arr[j-1];
			--j;
		}
		arr[j]=element;
	}
}

int main()
{
	int a[9];
	int j=0;
	//array creation
	a[0]=5;
	a[1]=4;
	a[2]=3;
	a[3]=2;
	a[4]=3;
	for(int i=5;i<9;i++)
		a[i]=i;
	cout<<"Before sorting:\n";
	for (int i = 0; i<9; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	InsertionSort(a,9);
	cout<<endl<<"After Sorting:\n";
	for (int i = 0; i<9; ++i)
	{
		cout<<a[i]<<" ";
	}
}
