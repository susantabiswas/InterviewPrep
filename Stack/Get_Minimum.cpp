//get the minimum element in constant time
/*
		keep track of the minimum element using a stack say minStack
		whenever we get an element smaller or equal to the top of minStack
		then push the element,
		During pop if the element is same as the minStack top then pop both
*/
#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class Stack{
public:
	Node *top;
	Node* minTop;
	Stack(){
		top = NULL;
		minTop = NULL;
	}
	Node* createNode(int data);
	void push(int data);
	int pop();
	int getMin();
	void disp();
};

void Stack:: disp(){
	Node* t = top;
	while(t){
		cout<<t->data<<" ";
		t = t->next;
	}
	cout<<endl;
}

Node* Stack:: createNode(int data){
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

void Stack:: push(int data){
	Node* node = createNode(data);

	if(top == NULL){
		top = node;
		if(minTop == NULL){
			Node* node1 = createNode(data);
			minTop = node1;
		}
	}
	else{
		node->next = top;
		top = node;

		if(data <= minTop->data){
			Node* node1 = createNode(data);
			node1->next = minTop;
			minTop = node1;
		}
	}
}

int Stack:: pop(){
	if(top == NULL){
		cout<<"Underflow";
		return -1;
	}

	Node* t = top;
	int data = t->data;
	top = top->next;
	delete t;

	if(data == minTop->data){
		Node* t = minTop;
		minTop = minTop->next;
		delete t;
	}
	return data;
}

int Stack:: getMin(){
	if(minTop!=NULL)
		return minTop->data;
	else{
		cout<<"No elements left\n";
		return -1;
	}
}
main(){
	vector<int> arr = {111,3,21,3,41,13,4,1,33};
	Stack s;
	for (int i = 0; i < arr.size(); ++i)
	{
		s.push(arr[i]);
	}
	s.disp();
	cout<<s.getMin()<<endl;
	s.pop();s.pop();s.pop();
cout<<s.getMin()<<endl;
s.disp();
}
