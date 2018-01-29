//Doubly Linked List Insertion
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

//for display
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//for node creation
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		return node;
	}
	else
		return NULL;
}

//for insertion in the begining
void insertBegin(Node** head,int data){
	Node *node = createNode(data);
	if(*head == NULL){
		*head = node;
	}
	else{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}

//for insertion in end
void insertEnd(Node** head,int data){
	Node *node = createNode(data);
	Node* t = *head;
	if(*head == NULL)
		*head = node;
	else{
		while(t->next){
			t = t->next;
		}
		t->next = node;
		node->prev = t;
	}
}

//for insertion at any position
void insertPos(Node** head,int data,int pos){
	if(*head == NULL){
		cout<<"Underflow";
		return;
	}
	Node* node = createNode(data);
	if(pos == 1){
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
	else{
		int count = 1;
		Node* temp = *head;
		while(temp->next && count<pos-1){
			++count;
			temp = temp->next;
		}

		//out of bound condition
		if(count<pos-1){
			cout<<"Out of bound";
			return;
		}
		node->next = temp->next;
		node->prev = temp;
		if(temp->next)
			temp->next->prev = node;
		temp->next = node;
	}
}

main(){
	Node* head = NULL;
	insertBegin(&head,1);
	insertBegin(&head,11);
	disp(head);
	insertEnd(&head,2);
	insertEnd(&head,3);
	insertEnd(&head,3);
	disp(head);
	insertPos(&head,1,1);
	disp(head);

	insertPos(&head,22,8);
	disp(head);
	//insertPos(&head,)
}
