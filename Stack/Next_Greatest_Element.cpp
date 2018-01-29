///Find the next greatest element for each element
/*
	create a stack
	Now start scanning:
		for each element:
			if the stack top is greater then 
				push the element
										
			else
				start popping elements:
				for each of those popped elements current element is the Next greatest element
	
	all those elements still remaining in stack :
		they have no greatest next element as an element can exist on top of 
		another only if is smaller



*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> findNextGreatest(vector<int> &arr){
	stack<int> s;
	int el;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(!s.empty()){
			while(!s.empty() && arr[s.top()]<arr[i]){
				el = s.top();
				s.pop();
				arr[el] = arr[i];
			}
			s.push(i);
		}
		else
			s.push(i);
	}

	while(!s.empty()){
			arr[s.top()] = -1;
			s.pop();
	}
	return arr;
}

//for display
void disp(vector<int> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
main(){
	vector<int> arr = {11, 13, 21, 3};
	vector<int> res = findNextGreatest(arr);
	disp(res);
}
