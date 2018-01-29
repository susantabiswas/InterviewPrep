//Finds the Maximum element(an element which has atleast n/2 occurence) from an array of element.

/*1.Sort the list
2.Then traverse through the list and since it is sorted the recurring elements will be present one after another
3.Check the next element if it is same or not
	if same then increment count else count=0
when traversed till n/2 check if count=0 then maximum element is not possible
*/
#include<iostream>
using namespace std;

int partition(int arr[],int l,int h)
{
	//pivot is the taken as the last element
	int pivot=arr[h];
	int i=l;
	int j=h-1;
	int swap=0;
	while(i<=j)
	{
		while(arr[i]<pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		//swap the elements
		if(i<=j)
		{
			swap=arr[i];
			arr[i]=arr[j];
			arr[j]=swap;
			i++;
			j--;
		}
	}
	//swap the pivot element
	swap=arr[h];
	arr[h]=arr[i];
	arr[i]=swap;

	return i;
}

//for quicksort
void quickSort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=partition(arr,l,h);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,h);
	}
}

//finds if maximum element is there or not
void maximumElement(int arr[],int n)
{
	int count=1;
	for (int i = 1; i < n; ++i)
	{
		if(arr[i]==arr[i-1])
			++count;

		else
		{
			count=1;
		}
		if(count>n/2)
			{
				cout<<"\nmaximum Element present and is:"<<arr[i]<<endl;
				return ;
			}
		if(i>n/2)
		{
			if(count==1)
				{cout<<"\nNONE\n";
					return ;
				}
		}
	}
}

//for displaying the array elements
void Display(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	//create an array
	int arr[]={3,3,4,2,4,4,2,4,4};
	int sum=0;
	int size=sizeof(arr)/sizeof(int);
	Display(arr,size);

	//sort the elements
	quickSort(arr,0,size-1);

	maximumElement(arr,size);

	return 0;
}
