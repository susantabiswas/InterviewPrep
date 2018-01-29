//Given an array of prices of shares.Give the maximum profit obtained by buying and
//selling a share for a day only once
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//finds the maximum profit from buying and selling of a share
/*
	Start with a share price and find the difference of the next share prices and check if
	that is greater than the max profit,if the difference becomes -ve then take take that
	price as the start price because -ve price means that that number can give greater profit
	if there exists a price which can give profit than using the current number that is greater
	than it
*/
double maxStockProfit(vector<double> &arr){
	double max_profit = 0;
	double start = arr.front();
	double price = numeric_limits<double>::max();

	for(int i =1 ;i<arr.size(); i++){
		price = arr[i] - start;

		if(price >max_profit)
			max_profit = price;
		else if(price < 0)
			start = arr[i];
	}
	return max_profit;
}

main(){
	vector<double> arr = {310,315,275,295,260,270,290,230,255,250};
	cout << maxStockProfit(arr);
}
