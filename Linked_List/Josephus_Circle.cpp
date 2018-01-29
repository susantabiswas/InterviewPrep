//Josephus Circle
#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

//linked list structure
//Node structure
struct Node{
	int data;
	Node *next;
};

void disp(Node* head){
	Node *temp =head;
	while(head->next != temp){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<head->data<<" ";
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

void insertEnd(Node** head,int data){
	Node *node = createNode(data);

	if(*head == NULL){
		*head = node;
		node->next = node;
		return;
	}

	Node *last = *head;
	while(last->next != *head){
		last = last->next;
	}
	node->next = *head;
	last->next = node;
}

Node* josephusCircleSimulator(Node* head,int m){
	Node* t = head;
	Node* t1 = NULL;
	Node* prev = NULL;
	int i = 1;
	while(t->next != t){
		i = 1;
		while(i<m && t->next != t){
			++i;
			prev = t;
			t = t->next;
		}
		t1 = t;
		t = t->next;
		prev->next = t;
		delete t1;
	}
	return t;
}

int main(){
	Node* h1 = NULL;
	for (int i = 1; i <=7; ++i)
	{
		insertEnd(&h1,i);
	}
	disp(h1);
	Node *ans = josephusCircleSimulator(h1,3);
	cout<<ans->data;
	return 0;
}
