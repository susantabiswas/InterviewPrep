//finds the number occurring odd number of times
/*There is only one number occurring odd number times .
We use XOR operation.Doing XOR on an element occurring odd number of times is that element and
on even is 0.A^0=A and A^A=0,also it is commutative and associative so order doesn't matter
NOTE:WORKS ONLY WHEN ALL OTHER NUMBERS HAVE EVEN OCCURRENCES AND ONLY ONE HAS ODD NUMBER OF OCCURRENCES
*/

#include<iostream>
using namespace std;

int getOddOccur(int arr[],int size)
{
	int result=0;
	for (int i = 0; i < size; ++i)
	{
		result=result^arr[i];
	}
	return result;
}

int main()
{
	int arr[]={1,1,2,2,3,3,5,5,1};
	int size=sizeof(arr)/sizeof(int);
	int res=getOddOccur(arr,size);
	cout<<"Number occurring odd number of times:"<<res<<endl;
}
