//Find the missing element from  a list of 1..n-1 elements
/*Elements are distinct and range from 1 to n.Input has a list of n-1 numbers and the missing number
needs to be found*/
#include<iostream>
using namespace std;

//finds the missing element
/*XOR all the 1..n elements and then XOR the given elements and XOR both the results
since if c is the missing element then when we XOR the results then we get 0^c that is c
As the common elements being getting XOR operation becomes 0*
Array contains n-1 elements .
But it contains distinct elements out of n elements */
int FindMissing(int arr[],int size)
{
	int res1=0;
	for (int i = 0; i < size; ++i)
	{
		res1=arr[i]^res1;
	}
	int res2=0;
	//here n=size+1
	for (int i = 1; i < size+2; ++i)
	{
		res2=res2^i;
	}
	return res1^res2;
}

int main()
{
	int arr[]={1, 2, 4, 6, 3, 7, 8};
	int size=sizeof(arr)/sizeof(int);
	cout<<"Missing element:"<<FindMissing(arr,size);
	return 0;
}
