//Finds the Maximum element(an element which has atleast n/2 occurrence) from an array of element using moore Algorithm

/*we find the most recurring element in the list
 then check if it is the majority element
*/
#include<iostream>
using namespace std;

//finds a candidate for majority element
int findMajority(int arr[],int n)
{
	int count=1;
	int maj=0;
	for (int i = 0; i < n-1; ++i)
	{
		if(arr[maj]==arr[i+1])
			++count;
		else if(arr[maj]!=arr[i+1])
			--count;
		if(count==0)
		{
			maj=i;
			count=1;
		}

	}
	return arr[maj];
}

//checks if the candidate element is really majority element or not
bool isMajority(int arr[],int n,int candidate)
{
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]==candidate)
			++count;
	}
	if(count>n/2)
		return true;
	else
		return false;
}


//finds if maximum element is there or not
void maximumElement(int arr[],int n)
{
	//find a candidate for majority element
	int candidate=findMajority(arr,n);
	int result=isMajority(arr,n,candidate);

	if(result)
		cout<<"Majority Element present,it is :"<<candidate<<endl;
	else
		cout<<"NONE\n";
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
	int r=3^4;cout<<r<<endl;
	int size=sizeof(arr)/sizeof(int);
	Display(arr,size);
	maximumElement(arr,size);

	return 0;
}
