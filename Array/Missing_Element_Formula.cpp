//Find the missing element from  a list of 1..n-1 elements
/*Elements are distinct and range from 1 to n.Input has a list of n-1 numbers and the missing number
needs to be found*/
#include<iostream>
using namespace std;

//finds the missing element
/*get the sum of 1 to n elements ,then the sum of given elements ,
subtracting the two,we get the missing element
Array contains n-1 elements .
But it contains distinct elements out of n elements
*/

int FindMissing(int arr[],int size)
{
	int res1=0;
	for (int i = 0; i < size; ++i)
	{
		res1=arr[i]+res1;
	}
	//sum formula ,here n=size+1 ,since size is actually 1 less than total elements
	int res2=(size+1)*(size+2)/2;

	return res2-res1;
}

int main()
{
	int arr[]={1, 2, 4 ,6, 3, 7, 8};
	int size=sizeof(arr)/sizeof(int);
	cout<<"Missing element:"<<FindMissing(arr,size);
	return 0;
}
