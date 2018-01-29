//Given an array .We have to separate the array elements into two 
//groups such that the difference of the sum of the two groups is 
//minimum
/*
	Following solution tries every cmb ,just like the pmt quest
*/

#include<iostream>
#include<vector>
#include<deque>
#include<limits>

using namespace std;

//for swapping data
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

//this uses backtracking for finding the two groups by using all possible cmb
void findMinDiff(vector<int> &arr, int l, int r, deque<int> &l1, deque<int> &l2,int &min_diff){
	if( l == arr.size()/2){
		//find the sum
		int n = arr.size();
		int a = 0;
		int b = 0;
		for(int i = 0,j = n-1; i<n/2 && j>=n/2; i++,j--){
			a = a + arr[i];
			b += arr[j];
			//cout<<a<<" "<<b<<" "<<a-b<<endl;
		}
		if((a-b) < min_diff){
				l1.clear();
				l2.clear();
			for(int i = 0,j = n-1; i<n/2 && j>=n/2; i++,j--){
				l1.push_back(arr[i]);
				l2.push_back(arr[j]);
				//cout<<a<<" "<<b<<" "<<a-b<<endl;
			}
		}
		return;
	}
	int diff;

	for(int i = l; i<=r; i++){
		swap(arr[l],arr[i]);
		findMinDiff(arr,l+1,r,l1,l2,min_diff);
		swap(arr[l],arr[i]);
	}

}

int main(){
	vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	deque<int> l1,l2;
	int min_diff = numeric_limits<int>::max();

	findMinDiff(arr,0,arr.size()-1,l1,l2,min_diff);
	deque<int>::iterator it;
	for(it = l1.begin(); it!=l1.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	for(it = l2.begin(); it!=l2.end(); it++)
		cout<<*it<<" ";
}
