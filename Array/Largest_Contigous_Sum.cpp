//Finds the largest contigous sum in a array of elements
//using Kadane's Algo.
#include<iostream>
using namespace std;

//finds the largest contigous sum
int largestSum(int arr[],int size)
{
	int MaxSoFar=0;
	int MaxHere=0;
	int MaxNegative=0;
	int countneg=0;
	for (int i = 0; i < size; ++i)
	{
		MaxHere=MaxHere+arr[i];

		if(MaxHere<0)
			MaxHere=0;

		if(MaxHere>MaxSoFar)
			MaxSoFar=MaxHere;

		//in case all the numbers are negative
		if(arr[i]<0)
		{
			//count the no. of negative numbers in the list
			++countneg;
			if(arr[i]>MaxNegative)
				MaxNegative=arr[i];
		}
	}
	//if there are only negative numbers in the array
	if(countneg==size)
		return MaxNegative;
	else
		return MaxSoFar;
}

int main()
{
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};

	int size=sizeof(arr)/sizeof(int);
	cout<<"Largest Contigous Sum:"<<largestSum(arr,size)<<endl;
	return 0;
}
