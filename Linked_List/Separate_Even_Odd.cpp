//Separate even and odd nodes.
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

void insertNode(Node** head,int data){
	Node* node = createNode(data);
	if(*head == NULL){
		*head = node;
	}
	else{
		node->next = *head;
		*head = node;
	}
}

Node* separateEvenOdd(Node* head){
	if(head == NULL)
		return NULL;

	Node* Ehead = NULL;
	Node* Ohead = NULL;
	Node* Eprev = NULL;
	Node* Oprev = NULL;

	while(head!=NULL){
		//if it is even
		if(head->data%2==0){
			if(Eprev == NULL){
				Ehead = head;
				Eprev = head;
			}
			else{
				Eprev->next = head;
				Eprev = head;
			}
		}//if it is odd
		else{
			if(Oprev == NULL){
				Ohead = head;
				Oprev = head;
			}
			else{
				Oprev->next = head;
				Oprev = head;
			}
		}
		head = head->next;
	}
	Eprev->next = Ohead;
	Oprev->next = NULL;

	return Ehead;
}

int main(){
	Node* h1 = NULL;
	insertNode(&h1,9);
	insertNode(&h1,7);
	insertNode(&h1,4);
	insertNode(&h1,3);
	insertNode(&h1,16);
	insertNode(&h1,19);
	insertNode(&h1,16);
	insertNode(&h1,11);
	disp(h1);

	Node* head = separateEvenOdd(h1);
	disp(head);
	return 0;
}
