//Merge Sort using Array
#include<iostream>
using namespace std;

//places the pivot element in its correct position in the list


//For performing quick sort
void quickSort(int *arr,int l,int h)
{
	//last element is selected as pivot element
	int pivot=arr[h];
	int i=l;
	int j=h-1;
	int swap=0;
	while(i<=j)
	{
		//traverse till there is an element greater or equal to pivot
		while(arr[i]<pivot)
			++i;
			//traverse till there is an element lesser or equal to pivot
		while(arr[j]>pivot)
			--j;
		if(i<=j)
		{	//swap the elements
			swap=arr[i];
			arr[i]=arr[j];
			arr[j]=swap;
			++i;
			--j;
		}

	}
	//swap the pivot element at its position
	swap=arr[i];
	arr[i]=arr[h];
	arr[h]=swap;

	//recursively call the function for the remaining part
	if(l<j)
		quickSort(arr,i,h);
	if(i<h)
		quickSort(arr,l,j);

}

int main()
{
	int a[5];
	int j=0;
	//array creation
	a[0]=5;
	a[1]=4;
	a[2]=3;
	a[3]=2;
	a[4]=3;
	cout<<"Before sorting:\n";
	for (int i = 0; i<5; ++i)
	{
		cout<<a[i]<<" ";
	}
	quickSort(a,0,4);
	cout<<endl<<"After Sorting:\n";
	for (int i = 0; i<5; ++i)
	{
		cout<<a[i]<<" ";
	}
}
