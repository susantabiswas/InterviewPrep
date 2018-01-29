//implement a stack using queue
/*
	Here push operation is costly O(n) and for pop O(1)
	Take 2 queues name them as q1 and q2.
	
	Now for push:
	push it in the empty queue q1 and then move elements
	if there in q2 into q1 .
	Now rename q1 to q2 and vice versa

	for pop:
	if both of them are empty 
		then error
	else 
		dequeue the first element of current q2
*/

#include<iostream>
#include<queue>
using namespace std;

void push(queue<int>* &q1 , queue<int>* &q2, int data){
	//we always need q1 to be empty
	if(!q1->empty() ){
		cout<<"Overflow !\n";
		return;
	}
	q1->push(data);

	//move elements from q2 to q1
	while(!q2->empty()){
		q1->push(q2->front());
		q2->pop();
	}

	//rename the queues
	queue<int> *q = q1;
	q1 = q2;
	q2 = q;

	cout<<"q1 size: "<<q1->size()<<"q2 size: "<<q2->size()<<endl;
}

//for pop operation
void pop(queue<int>* &q1,queue<int>* &q2){
	if(q2->empty()){
		cout<<"Underflow !\n";
		return;
	}

	q2->pop();
	cout<<"data: "<<q1->front() <<"size: "<<q1->size()<<"q2 size: "<<q2->size()<<endl;
}

main(){
	queue<int> *q1 = new queue<int>;
	queue<int> *q2 = new queue<int>;
	push(q1,q2,1);
	push(q1,q2,2);
	push(q1,q2,3);
	push(q1,q2,4);

	pop(q1,q2);
	push(q1,q2,4);
}
