//Check the given number exists as a sum of two numbers in a given array of elements

/*For this we sort the array
take a counter from start and one from the its next element
then if the sum of both is greater than sum,then return else increment the counter*/
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

void Display(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool sumCheck(int arr[],int sum,int size)
{
	//'i':starts from beginning and 'j':starts from the end
	int i=0;
	int j=size-1;
	//if list has more than one element
	while(i<j)
	{
		//if sum is greater ,go to next bigger element in the list
		if(arr[i]+arr[j]<sum)
			++i;
		//if sum is lesser ,go to previous smaller element in the list
		else if(arr[i]+arr[j]>sum)
			--j;
		else if(arr[i]+arr[j]==sum)
			return true;
	}
	//if list is empty or has one element
	return false;

}

int main()
{
	//create an array
	int arr[]={22,1,4,3,6,76,4};
	int sum=0;
	int size=sizeof(arr)/sizeof(int);
	Display(arr,size);

	//sort the elements
	quickSort(arr,0,size-1);
	cout<<"After sorting:\n";
	Display(arr,size);

	cout<<"Enter the sum to find\n";
	cin>>sum;
	bool result=sumCheck(arr,sum,size);
	if(result)
		cout<<"Sum is there\n";
	else
		cout<<"sum is not there\n";

	return 0;
}
