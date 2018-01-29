//given two sorted arrays of same size.Find the median if the two arrays are merged
//Time Complexity: O(logn)
#include<iostream>
#include<vector>
using namespace std;

//finds the median of two sorted arrays
/*
	if the m1 is the median of array1 and m2 is the median of array2 then :
	if m1 > m2:
		it means all elements on LHS of m2 will lie on left side of m1 ,so median
		will shift for the sorted array.Since elements on LHS of m1 have increased
		so for m1 the median is in the LHS and for m2 ,elements on RHS
		may be on LHS of m1 or may not be,so its median will be in RHS

	keep doing this untill each array has 2 elements remaining
	when there are 2 elements in each array then,
		median = (max(a[0],b[0]) + min(a[1],b[1]) ) /2
*/
int findMedian(vector<int> a, vector<int> b){
	//check if the elements left are 2 for each array or not
	if(a.size() == 2 && b.size() == 2)
		return (max(a[0],b[0]) + min(a[1],b[1]) )/2;

	int m1 = a.size()/2;
	int m2 = b.size()/2;

	//median lie in LHS of a and RHS of b
	if(a[m1] > b[m2]){
		return findMedian(vector<int> {a.begin(),a.begin()+m1+1},
						vector<int> {b.begin()+ m2,b.end()}
				);
	}
	else if(a[m1] < b[m2]){
		return findMedian(vector<int> {a.begin()+ m1,a.end()},
						vector<int> {b.begin(),b.begin()+m2+1}
					);
	}
	//when the medians are same
	else
		return a[m1];
}

int main(){
	vector<int> a = {1, 12, 15, 26, 38};
	vector<int> b = {2, 13, 17, 30, 45};
	int median = 0;
	cout<< findMedian(a,b);
}
