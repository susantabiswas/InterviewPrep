//reverse a  linked list iterative solution
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int data){
	Node* node = new Node;
	node->next = NULL;
	node->data = data;
	return node;
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

//for disp
void disp(Node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

Node* reverseNodesRec(Node* head){
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;

	Node* nextptr = head->next;
	head->next = NULL;
	Node *rev = reverseNodesRec(nextptr);
	nextptr->next = head;
	return rev;
}

Node* reverseNodesIter(Node* head){
		if (head == NULL)
			return NULL;

		Node* prev = NULL;
		Node* nextptr = head->next;
		prev = head;
		prev->next = NULL;
		head = nextptr;

		while(head){
			nextptr = head->next;
			head->next = prev;
			prev = head;
			head = nextptr;
		}
		return prev;
}

main(){
	Node* head = NULL;
	for (int i = 0; i < 7; ++i)
	{
		insertNode(&head,i);
	}
	disp(head);
	Node* h1 = reverseNodesIter(head);
	disp(h1);
	//Node* h2 = reverseNodesRec(head);
	//disp(h2);
}
