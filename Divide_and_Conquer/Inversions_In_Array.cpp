//given an array.Find the no. of inversions in that array
//An inversion is when a[i] > a[j] ,i<j
/*
	Can be calculated using merge sort ,as in it can know the time when an
	inversion occurs during the merge step
	So we count inversion for all merge steps and that is the inversion count for the
	array
*/
#include<iostream>
#include<vector>
using namespace std;

//for merging the sorted arrays and finding the inversion count
int merge(vector<int> &arr, int l, int r, int mid){
	//size for left array
	int n1 = mid - l + 1;
	//size for right array
	int n2 = r - mid ;

	//for keeping count of inversions
	int c = 0;
	//now create a temporary array for sorting the result
	vector<int> temp(n1 + n2);

	//now start counting the inversions and sort as well during the process
	//for left subarray
	int i = l;
	//for right subarray
	int j = mid + 1;
	//for temp array
	int in = 0;
	while(i <= mid && j <=r){
		//when inversion occurs
		if(arr[i] > arr[j]){
			//all the elements fom a[i] till a[mid] will be greater than a[j]
			//so these many elements contribute to the total count 
			c += mid - i + 1;
			temp[in++] = arr[j++];
		}
		else{
			temp[in++] = arr[i++];
		}
	}

	while(i<=mid)
		temp[in++] = arr[i++];
	while(j<=r)
		temp[in++] = arr[j++];

	//now copy to original array
	for(int i = 0; i<temp.size(); i++)
		arr[i+l] = temp[i];
	return c;
}

//for counting Inversions using Merge Sort
int countInversions(vector<int> &arr,int l,int r){
	if(l<r){
		int mid = l + (r-l)/2;
		int c1 = countInversions(arr,l,mid);
		int c2 = countInversions(arr,mid+1,r);
		int count = merge(arr,l,r,mid);
		return count + c1 + c2;
	}
	return 0;
}

int main(){
	vector<int> arr = {1, 20, 6, 4, 5};
	cout<< countInversions(arr,0,arr.size()-1);
}
