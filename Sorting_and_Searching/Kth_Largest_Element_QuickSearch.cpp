//given an array a and 'k' .Find the kth largest element
/*
	Can be solved using quick sort like method where we stop when the pivot position
	is equal to 'k'
	We use random position for selection pivot element
	TC: O(nlogn) avg
		worst : O(n^2)

*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void disp(vector<int> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//for swapping
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

//for partitioning
int partition(std::vector<int> &arr, int l, int r){
	//take the last element as the pivot
	int pivot = arr[r];
	int write = l;
	int i = l;
	while(i <= r-1){
		if(arr[i]<= pivot)
			swap(arr[write++],arr[i]);
		i++;
	}
	swap(arr[write],arr[r]);
	return write;
}

//for finding the kth largest element
int kthLargestElement(vector<int> &arr, int l, int r, int k){
	if(l<=r ){

		srand(time(NULL));
		int n = r-l+1;
		//generate a random pivot pos.
		int p = rand()%n;
		//swap the random pivot element with the last
		swap(arr[p+l],arr[r]);

		p = partition(arr,l,r);

		if(p == k-1)
			return arr[p];
		else if((p) > k-1)
			return kthLargestElement(arr,l,p-1,k);
		else if((p) < k-1)
			return kthLargestElement(arr,p+1,r,k);
	}
	return -1;
}



int main(){
	vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
	int k = 4;
	cout<< kthLargestElement(arr,0,arr.size()-1,k);
	return 0;
}
