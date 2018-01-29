//implement a queue using stack
/*
	we use 2 stacks for this
	we need to make sure that the oldest element always remains on top of others
	PUSH:
	while s1 is not empty move elements from it to s2
	then push into s1,and move all previous elements from s2 to s1

	POP:
	pop element from s1
*/
#include<iostream>
#include<stack>
using namespace std;

void enqueue(stack<int>* &s1,stack<int>* &s2, int data){
	//move elements from s1 to s2
	while(!s1->empty()){
		s2->push(s1->top());
		s1->pop();
	}
	s1->push(data);

	//again move elements from s2 to s1
	while(!s2->empty()){
		s1->push(s2->top());
		s2->pop();
	}
	cout<<"data:"<<data<<" s1 size:"<<s1->size()<<" s2 size:"<<s2->size()<<endl;
}

void dequeue(stack<int>* &s1,stack<int>* &s2){
	if(s1->empty())
		cout<<"Underflow\n";
	else
		s1->pop();
	cout<<"s1 size:"<<s1->size()<<" s2 size:"<<s2->size()<<endl;
}

main(){
	stack<int> *s1 = new stack<int>;
	stack<int> *s2 = new stack<int>;

	dequeue(s1,s2);
	enqueue(s1,s2,1);
	enqueue(s1,s2,2);
	enqueue(s1,s2,3);
	enqueue(s1,s2,4);
	enqueue(s1,s2,5);

	dequeue(s1,s2);
	cout<<s1->top();
	dequeue(s1,s2);
	cout<<s1->top();
}
