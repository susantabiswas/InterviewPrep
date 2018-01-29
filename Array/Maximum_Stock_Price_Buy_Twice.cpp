//Given the share prices for i days.Maximise the profit if the shares can be sold twice
#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

template <class T>
void disp(T arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//finds the maximum profit
/*
	We calculate the maximum profit for till ith day and store in F by travrsing forward
	Then we calculate the maximum profit that we can get after ith day by traversing from
	the back and store in B
*/

float findMaxProfit(vector<float> &arr){
	float max_profit = 0;
	float curr_profit = 0;
	float max_el = numeric_limits<float>::min();
	float min_el = numeric_limits<float>::max();
	//for storing the max profit till i-th day
	vector<float> F(arr.size(),0);
	float total_profit = 0;

	//first calculate the forward profit
	//here we keep track of the smallest element
	for(int i =0;i<arr.size() ;i++){
		curr_profit = arr[i] - min_el;
		max_profit = max(max_profit , curr_profit);
		min_el = min(min_el,arr[i]);

		F[i] = max_profit;
	}

	//disp(F);
	//first calculate the backward profit
	//here we keep track of the maximum element since to maximise from back we should
	//have the track record of max element
	max_profit = 0;
	curr_profit = 0;

	for(int i = arr.size()-1; i>0 ;i--){
		curr_profit = max_el - arr[i];
		max_profit = max(max_profit , curr_profit);
		max_el = max(max_el,arr[i]);

		F[i] = max(max_profit,max_profit + F[i-1]);
		if(F[i]>total_profit)
			total_profit = F[i];
	//	cout<<F[i]<<" ";
	}
	//cout<<endl;
	//disp(F);
	return total_profit;
}

main(){
	vector<float> arr = {12,11,13,9,12,8,14,13,15};
	cout<< findMaxProfit(arr);
}
