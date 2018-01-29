//Count Sort
/*
	Whenever we know the range of numbers then we can use count sort
	It uses an array of size of 'n' which is range of element value and stores
	the count of element in that array
	then display the elements as per their count
	TC:O(k+n),k:max value,n:no of elements
*/
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//for count sort
void countSort(vector<int> &arr){
	//find the max element to decide the range
	int max_el = numeric_limits<int>::min();
	for (int i = 0; i < arr.size(); ++i)
	{
		if(arr[i] > max_el)
			max_el = arr[i];
	}

	//create an array for the range
	vector<int> res(max_el+1,0);

	//now count the frequency of elements
	for (int i = 0; i < arr.size(); ++i)
	{
		res[arr[i]]++;
	}

	int in = 0;
	//now copy the sorted elements to the original array
	for (int i = 0; i < res.size(); ++i)
	{
		while(res[i] != 0){
			arr[in++] = i;
			res[i]--;
		}
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
	vector<int> arr = {2,1,2,1,2,4,5,4,5,4,6,4,8,7,9,45,1,2,5,7,99};
	countSort(arr);
	disp(arr);
}
