//Given an array where each element represent the height of a building and consider they
//have the same breadth.Find the largest rectangle possible
/*
	for each height 'x' we find the first smaller building on the left and on the right
	make a stack
	if the height is greater then
		push
	if the height is smaller
		keep popping till you get an element smaller than the current
		for each popped element 'x' the left index is the next top stack and right
		is the current smallest element
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int maxRectangleArea(vector<int> &arr){
	int currArea = 0;
	int maxArea = 0;
	int h = 0;
	stack<int> s;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(!s.empty()){
			if(arr[i]>=arr[s.top()])
				s.push(i);
			else{
				while(!s.empty() && arr[s.top()]>arr[i]){
					h = s.top();
					s.pop();
					currArea = arr[h]*(s.empty()?h:(i - s.top()-1));
					if(currArea >  maxArea){
						maxArea = currArea;
					}
				}
				s.push(i);
			}
		}
		else
			s.push(i);
	}
 
	if(!s.empty()){
		h = s.top();
		s.pop();
		currArea = arr[h]*(s.empty()?h:(h - s.top()));
		if(currArea > maxArea)
			maxArea = currArea;
	}
	return maxArea;
}

main(){
	vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
	cout<<maxRectangleArea(arr);
}
