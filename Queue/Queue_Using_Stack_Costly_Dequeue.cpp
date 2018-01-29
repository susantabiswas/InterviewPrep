//queue using stack with costly
/*
	Since the dequeue is costly so,
	enqueue:
		push in s1
	dequeue:
		if s1 and s2 both are empty
			error
		if s2 is not empty
			pop from there
		else
			move all the elements from s1 to s2
*/
#include<iostream>
#include<stack>
using namespace std;

void enqueue(stack<int>* &s1,stack<int>* &s2, int data){
	s1->push(data);
	cout<<"data:"<<data<<" s1 size:"<<s1->size()<<" s2 size:"<<s2->size()<<endl;
}

void dequeue(stack<int>* &s1,stack<int>* &s2){
	//check for underflow
	if(s1->empty() && s2->empty())
		cout<<" underflow\n";
	//check if s2 is empty or not
	else if(!s2->empty())
		s2->pop();
	else{
		//move elements from s1
		while(!s1->empty()){
			s2->push(s1->top());
			s1->pop();
		}
		s2->pop();
	}
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
	cout<<s2->top();
	dequeue(s1,s2);
	cout<<s2->top();
}
