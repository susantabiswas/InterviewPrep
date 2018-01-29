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

vector<int> incrementNum(vector<int> &arr){

	//start from back and proceed further
	int carry = 0;
	int digit = 0;

	vector<int> ::reverse_iterator rit;

	//set the last digit
	arr[arr.size()-1] += 1;
	carry = arr[arr.size()-1] /10;
	arr[arr.size()-1] %= 10;

	rit = arr.rbegin();
	rit++;
	for(;rit!= arr.rend();rit++){

		*rit = *rit  + carry;
		carry = *rit / 10;
		*rit = *rit % 10;

	}

	if(carry!= 0)
		arr.insert(arr.begin(),carry);

		//cout<<arr.size();
	return arr;
}

int main(){
	vector<int> arr = {1,2,9};

	arr = incrementNum(arr);
	disp(arr);
	return 0;
}
