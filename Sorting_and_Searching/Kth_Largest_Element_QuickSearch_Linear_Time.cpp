//given an arraya and 'k' .Find the kth largest element
/*
	Can be solved using quick sort like method where we stop when the pivot position
	is equal to 'k'
	We use median position for selection pivot element and selection of median is
	done in linear time
	Tc : O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
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
int partition(std::vector<int> &arr, int l, int r, int x){
	//find the median
	//and swap it with the last element
	for (int i = l; i <=r; ++i)
	{
		if(arr[i] == x)
			swap(arr[i],arr[r]);
	}

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

//for finding the median of elements
int findMedian(vector<int> arr){
	sort(arr.begin(),arr.end());
	return arr[arr.size()/2];
}

//for finding the kth largest element
int kthLargestElement(vector<int> &arr, int l, int r, int k){
	if(k>0 && k<=r-l+1 ){
		int i = 0;
		int n = r - l +1;
		//divide the array into groups of 5 and find their median
		vector<int> median((n+4)/5);
		for(i = 0; i<n/5; i++){
			median[i] = findMedian(vector<int>{arr.begin() + l + i*5,
									arr.begin() + l + i*5 + 5});
		}
		//see if there are any elements left not being in group of 5
		if(i*5 < n){
			median[i] = findMedian(vector<int>{arr.begin() + l + i*5,
									arr.begin() + l + i*5 + n%5});
		}
		//now find the median of medians
		int med_of_med = kthLargestElement(arr,0,i-1,i/2);

		int p = partition(arr,l,r,med_of_med);

		if((p-l) == k-1)
			return arr[p];
		else if((p-l) > k-1)
			return kthLargestElement(arr,l,p-1,k);
		else if((p-l) < k-1)
			return kthLargestElement(arr,p+1,r,(k-1) - p + l);
	}
	return -1;
}



int main(){
	vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
	int k = 3;
	cout<< kthLargestElement(arr,0,arr.size()-1,k);
	return 0;
}
