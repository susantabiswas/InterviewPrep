//Insertion in linked list
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

//display function
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//for creation of node
Node* createNode(int data){
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

//for insertion in begining
Node* insertBegin(Node **head,int data){
	Node *node = createNode(data);

	if(*head==NULL){
		*head = node;
	}
	else{
		node->next = (*head);
		*head = node;
	}
	return *head;
}

//for insertion in begining
Node* insertBegin1(Node *head,int data){
	Node *node = createNode(data);

	if(head == NULL){
		head = node;
	}
	else{
		node->next = head;
		head = node;
	}
	return head;
}
//for insertion at any position
void insertPos(Node** head,int data,int pos){
	int count = 0;
	try{
		if(pos == 1){
			*head = insertBegin(head,data);
		}
		else{
			++count;
			Node *temp = *head;
			Node *node = createNode(data);
			while(temp && count < pos-1){
				++count;
				temp = temp->next;
			}
			if(temp){
				node->next = temp->next;
				temp->next = node;
			}
			else
				throw -1;
		}

	}
	catch(int e){
		if(e == -1){
			cout<<"Given positon doesn't exist for the linkedlist";
		}
	}
}

int main(){

	Node *head = NULL;
	head = insertBegin1(head,2);
	head = insertBegin1(head,3);
	insertBegin(&head,4);
	disp(head);

	insertPos(&head,5,2);
	disp(head);
	return 0;
}
