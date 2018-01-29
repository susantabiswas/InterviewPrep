//sort the stack using only recursion and stack in built methods
/*
	During recursion keep popping data in each recursive call
	now when moving from bottom we call another function which takes the 
	current stack and starts popping the element till we get in a sitution when the 
	stack top is smaller than the current data element ,so we place the data element and 
	end the recursive call for it and return to the main recursive call

	in each step if are just placing the element in its correct position in the stack
*/
#include<iostream>
#include<stack>
using namespace std;

void arrangeElements(stack<int> &s,int data){
	if(s.empty())
		s.push(data);
	else{
		if(!s.empty()){
			if(data>=s.top())
				s.push(data);
			else{
				int el = s.top();
				s.pop();
				arrangeElements(s,data);
				s.push(el);
			}
		}
	}
}

void sortStack(stack<int> &s){
	if(s.empty())
		return;
	int data = s.top();
	s.pop();
	sortStack(s);
	arrangeElements(s,data);
}



void disp(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

main(){
	stack<int> s;
	s.push(23);
	s.push(9);
	s.push(8);
	s.push(-3);
	s.push(13);

	s.push(3);
	s.push(2);
	cout<<endl;

	sortStack(s);
	disp(s);
}
