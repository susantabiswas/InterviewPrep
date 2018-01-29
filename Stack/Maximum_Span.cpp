//given an array .Find the maximum abs(i-j) such that a[j]<=a[i] ,j<i
//or find the maximum span for i such that a[i]>=a[j] where j<i
/*
	start scanning:
		for current element we pop elements till the stack top 
		becomes greater than the current element or the stack 
		becomes empty.Then we just subtract that index 
		current index.Then push the current element index
*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> computeSpan(vector<int> &arr){
	vector<int> span(arr.size());
	stack<int> s;
	int pos = -1;

	for(int i = 0; i<arr.size(); i++){
		while(!s.empty() && arr[s.top()]<arr[i])
			s.pop();
		if(s.empty())
			pos = -1;
		else
			pos = s.top();

		span[i] = i-pos;
		s.push(i);
	}
	return span;
}

void disp(vector<int> arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}
main(){
	vector<int> arr = {1,23,12,3,5,3,3,223,21,3};
	vector<int> span = computeSpan(arr);
	cout<<*max_element(begin(span),end(span))<<endl;
	disp(span);
}
