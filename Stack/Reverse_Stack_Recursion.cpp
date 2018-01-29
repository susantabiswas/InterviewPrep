//Reverse a stack using recursion
/*
	Start recursion and in each call pop an element
	Now on moving backwards in the recursive stack do:
		call a function which moves the current element in the last of stack
		
*/
#include<iostream>
#include<stack>
using namespace std;

void pushLast(stack<int> &s,int data){
	if(s.empty())
		s.push(data);
	else{
		if(!s.empty()){
			int el = s.top();
			s.pop();
			pushLast(s,data);
			s.push(el);
		}
	}
}

void reverseStack(stack<int> &s){
	if(s.empty())
		return;
	int data = s.top();
	s.pop();
	reverseStack(s);
	pushLast(s,data);
}



void disp(stack<int> s){
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
}

main(){
	stack<int> s;
	for (int i = 1; i < 6; ++i)
	{
		s.push(i);
		cout<<i<<" ";
	}
	cout<<endl;

	reverseStack(s);
	disp(s);
}
