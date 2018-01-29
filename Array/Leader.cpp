//prints all those elements which are greater than all elements which lies right to them.
#include<iostream>
using namespace std;

//the required function
/*start from rightmost element and traverse left till a element is found which is greater ,
print it and carry on doing this
*/
void printReqElements(int arr[],int size)
{
	cout<<arr[size-1]<<" ";
	int j=size-1;

	int temp=arr[size-1];

	--j;
	while(j>0)
	{
		while(arr[j]<temp && j>=0)
			--j;
		cout<<arr[j]<<" ";
		temp=arr[j];
		--j;
	}

}

//displays the array elements
void display(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[]={16, 17, 4, 3, 5, 2};
	int size=sizeof(arr)/sizeof(int);

	cout<<"Contents:\n";
	display(arr,size);
	cout<<"Elements are:\n";
	printReqElements(arr,size);

	return 0;
}
