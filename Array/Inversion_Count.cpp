//Counts the no. of inversions in an array.
/*An inversion is said to occur if a[i]>a[j],where i<j*
done using merge sort ,
in the merge step during comparison of arr1[i]>arr2[j],if it is true that means arr2[j] is smaller than every element >=arr1[i],
so inversion count is incremented by that many elements.
Time Comp:O(nlogn)
*/
#include<iostream>
using namespace std;

//keeps track of total inversions
int inversionCount=0;


//For Merging the two sub arrays
//l:lower index,m=:mid index,h:higher index
void Merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    //copy the arrays into temporary arrays
    int a1[n1];
    int a2[n2];

	//copy elements in the temporary arrays
    for (int i = 0; i <n1; ++i)
    {
        a1[i]=arr[i+l];
    }

    for (int i = 0; i < n2; ++i)
    {
        a2[i]=arr[i+m+1];
    }

    //starting index of first ,second sub arrays and merged array
    int i=0,j=0,index=l;
    while(i<n1 && j<n2)
    {
        if (a1[i]<a2[j])
        {
            arr[index++]=a1[i++];
        }
        else
        {   /*arr2[j] is smaller than every element >=arr1[i],
            so inversion count is incremented by that many elements.
            */
            arr[index++]=a2[j++];
            inversionCount+=n1-i;
        }
    }

    //if a1 has finished while a2 is left
    while(i>=n1 && j<n2)
        arr[index++]=a2[j++];
    //if s2 has finished while a1 is left
     while(j>=n2 && i<n1)
        arr[index++]=a1[i++];
}

//For performing Merge sort
void MergeSort(int arr[],int l,int h)
{
    //if the array has only one element or empty
   if(l<h)
  {
    int m=(l+h)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,h);

    //merge the subarrays
    Merge(arr,l,m,h);
   }
}

//for displaying the array elements
void display(int arr[],int size)
{
	for (int i = 0; i<5; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//counts the inversions
int countInversions(int arr[],int l,int h)
{
	MergeSort(arr,l,h);
	return inversionCount;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int size=sizeof(arr)/sizeof(int);

    cout<<"Before sorting:\n";
    display(arr,size);

    cout<<"Total Inversions:"<<countInversions(arr,0,size-1);
 }
