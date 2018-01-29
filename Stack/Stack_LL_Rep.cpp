//Stack using linked list
#include<iostream>
#include<cstdlib>
#include<exception>
#include<limits>
using namespace std;

//linked list structure
//Node structure
struct Node{
	int data;
	Node *next;
};

//display function
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//for creation of node
Node *createNode(int data){
	try{
		Node *node = new Node;
		node->data = data;
		node->next = NULL;
		return node;
	}
	catch(exception& e){
		cout<<e.what();
		exit(1);
	}
}

void push(Node** head,int data){
	Node* node = createNode(data);
	if(*head == NULL){
		*head = node;
	}
	else{
		node->next = *head;
		*head = node;
	}
}

int pop(Node** head){
	if(head == NULL)
		return  numeric_limits<int>::min();
	else{
		int t = (*head)->data;
		Node* temp = *head;
		*head = (*head)->next;
		delete temp;
		return t;
	}
}

int main(){
	Node* top = NULL;
	for(int i = 1;i<7;i++)
		push(&top,i);
	disp(top);

	pop(&top);
	pop(&top);
	disp(top);
	return 0;
}
