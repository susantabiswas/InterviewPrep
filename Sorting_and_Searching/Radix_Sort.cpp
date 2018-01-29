//radix sort
/*
	In this it sorts the elements acc. to their digits
	say the max value has 4 digits ,then it will sort all acc. to first 1s place
	using count sort in linear time then for 10s place ,100s place and so on
	so TC: O(d * (n + b))
	b = base
	n = num of elements
	d = no. of digits
	now d = log base b (k) where k is the max value
	TC: O( logb(k) * (n + b))
	we set k <= n^c
	and base b = n
	then Tc :O(n)
	So if given an array with max value in n^c and base n then we can use this sort

*/
#include<iostream>
#include<vector>
using namespace std;

//count sort required for radix sort
void countSort(vector<int> &arr, int d){
	//for counts of digits 0-9
	vector<int> count(10);
	vector<int> res(arr.size()+1);

	//make count array values
	for (int i = 0; i < arr.size(); ++i)
	{
		count[(arr[i]/d)%10]++;
	}

	//modify count such that count[i] knows at what index its last value will be
	//by adding the previous count value with it
	for (int i = 1; i < count.size(); ++i)
	{
		count[i] += count[i-1];
	}

	//store the result
	for (int i = arr.size()-1; i >= 0; --i)
	{
		res[count[ (arr[i]/d)%10 ] - 1] = arr[i];
		count[(arr[i]/d)%10]--;
	}
	//modify the original array
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = res[i];
	}
}

//for radix sort
void radixSort(vector<int> &arr){
	//we use count sort for d times where d is no of digits in max num
	//so we find the max num
	int max = arr[0];
	for(int i = 0; i<arr.size(); i++)
		if(max < arr[i])
			max = arr[i];

	//then we call count sort
	//here 'i' keeps track of the place whether 1s ,10s etc
	for(int i = 1; max/i > 0; i = i*10){
		countSort(arr,i);
	}
}

//for displaying the elements of the array
void disp(vector<int> arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
	radixSort(arr);
	disp(arr);
}
