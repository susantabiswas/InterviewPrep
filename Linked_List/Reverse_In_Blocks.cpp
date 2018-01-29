//Reverse the nodes in blocks.Given k ,which is the number of elements in a  block to reverse
//given: 1,2,3,4,5  k=3 ==> 3,2,1,4,5
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

Node* reverseInBlocks(Node* head,int k){
	if(head == NULL)
		return NULL;
	Node* t = head;
	int i = 1;
	Node* nextptr = NULL;
	Node* prev = NULL;
	Node* new_head = NULL;

	while(head){
		t = head;
		i = 1;
		while(i<k && t){
			t = t->next;
			++i;
		}
		if(t==NULL)
			break;

		nextptr = t->next;
		t->next = NULL;

		if(prev!=NULL){
			prev->next = reverseNodesRec(head);
		}
		else{
			new_head = reverseNodesRec(head);
		}


		prev = head;
		head->next = NULL;
		head = nextptr;
	}
	prev->next = head;
	return new_head;
}

int main(){
	Node* h1 = NULL;
	insertNode(&h1,9);
	insertNode(&h1,79);
	insertNode(&h1,4);
	insertNode(&h1,13);
	insertNode(&h1,4);
	insertNode(&h1,7);
	insertNode(&h1,9);

	disp(h1);

	Node* head = reverseInBlocks(h1,2);
	disp(head);
	return 0;
}
