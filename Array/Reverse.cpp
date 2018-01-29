#include<iostream>
#include<vector>
using namespace std;

//start from the begining and from the end  and keep swapping the
//elements
void reverse(vector<int>& arr){
	int n = arr.size();
	int t;
	int i = 0;
	int j = n-1;
	while(i <= j){
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
		++i,--j;
	}
}

int main(){

	vector<int> arr = {1,2,3,4,5,6};
	reverse(arr);

	for(int i = 0; i<arr.size(); i++)
		cout << arr[i] << " ";
	return 0;
}
