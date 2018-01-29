//Given an array representation of a decimal number.Increment its value
#include<iostream>
#include<vector>
using namespace std;

//for displaying  the vector
template <class T>
void disp(T &arr){
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

vector<int> incrementNum(vector<int> arr){

	//start from back and proceed further
	int carry = 1;
	int digit = 0;
	vector<int> new_num(0);
	vector<int> ::reverse_iterator rit;

	for(rit = arr.rbegin();rit!= arr.rend();rit++){
		digit = *rit  + carry;
		carry = digit / 10;
		*rit = digit % 10;
	}

	if(carry != 0){
		new_num.push_back(carry);
	}

	vector<int> ::iterator it;
	for(it = arr.begin();it!=arr.end();it++)
		new_num.push_back(*it);

	return new_num;
}

int main(){
	vector<int> arr = {1,2,9};
	arr = incrementNum(arr);
	disp(arr);
	return 0;
}
