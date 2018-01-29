//find the maximum such that no two elements are adjacent
#include<iostream>
#include<vector>
using namespace std;

/*
	We use two variables one which stores the max sum till that point without
	including the previous element 'exc' and one which includes the previous element
	'inc'.

	inc = array[0]
	start traversing the array:
		since the elements can't be adjacent so :

		exc_i will not be including the current element so it is max of
		previous two variables
		exc_i = max( exc_i, inc_i)

		since inc_i will be including the current variable so it needs exc_i-1 and
		adds the current element
		inc_i = exc_i + array[i]

	return max( inc_n, exc_n)
*/
int maxSum(vector<int>& arr){
	int exc = 0;
	int inc = arr[0];
	int t;

	for(int i = 1; i<arr.size(); i++){
		t = max(inc, exc);
		//update the max sum including the current element
		inc = exc + arr[i];

		//update the max sum excluding the current element
		exc = t;

	}
	return max(inc, exc);
}

int main(){
	vector<int> arr = {5, 5, 10, 100, 10, 5};
	cout << maxSum(arr);
}
