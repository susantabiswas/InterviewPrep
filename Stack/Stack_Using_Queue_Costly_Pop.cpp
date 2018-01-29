//implement a stack using queue
/*
	Here pop operation is costly O(n) and for push O(1)
	Take 2 queues name them as q1 and q2.
	push:
		if q1 is full error
		else
			enqueue in q1
 	pop:
 		if q1 is empty then error
 		else
 			dequeue all elements except the last fom q1 to q2
 			rename q1 to q2 and vice versa
*/
#include<iostream>
#include<queue>
using namespace std;

void push(queue<int>* &q1,queue<int>* &q2, int data){
	q1->push(data);
	cout<<"q1 size: "<<q1->size()<<"q2 size: "<<q2->size()<<endl;
}

void pop(queue<int>* &q1,queue<int>* q2){
	int i = 1;
	int n = q1->size();
	//move all elements from q1 to q2 except last
	if(q1->empty() ){
		cout<<"Underflow !\n";
		return;
	}
	//dequeue elements from q1
	while(!q1->empty() && i++<n){
		q2->push(q1->front());
		q1->pop();
	}
	cout<<"data: "<<q1->front() <<"size: "<<q1->size()<<"q2 size: "<<q2->size()<<endl;
	q1->pop();

	//rename the queues
	queue<int> *q = q1;
	q1 = q2;
	q2 = q;

}

main(){
	queue<int> *q1 = new queue<int> ;
	queue<int> *q2 = new queue<int>;

	push(q1,q2,1);
	push(q1,q2,2);
	push(q1,q2,3);
	push(q1,q2,4);

	pop(q1,q2);
	push(q1,q2,4);
}
