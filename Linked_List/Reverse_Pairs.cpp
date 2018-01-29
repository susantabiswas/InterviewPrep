//reverse the numbers in pairs
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

Node* reversePairsRec(Node* head){
	if(head == NULL || head->next ==NULL)
		return head;
	Node* nextptr = head->next;
	head->next = reversePairsRec(nextptr->next);
	nextptr->next = head;
	return nextptr;
}

Node* reversePairsIter(Node* head){
	if(head== NULL || head->next==NULL)
		return head;

	Node* new_head = head->next;
	Node* t = head;
	Node* prev = NULL;
	Node* nextptr = NULL;
	while(t && t->next){
		nextptr = t->next->next;
		if(prev!= NULL){
			prev->next = t->next;
		}
		prev = t;
		t->next->next = t;
		t->next = NULL;
		t = nextptr;
	}
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
	//insertNode(&h1,9);

	disp(h1);

	//Node* head = reversePairsRec(h1);
	//disp(head);

	Node* head = reversePairsIter(h1);
	disp(head);
	return 0;
}
