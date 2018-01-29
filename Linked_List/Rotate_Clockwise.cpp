//rotate linked list clockwise
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

Node* rotateClockwise(Node* head,int k){
	if(head == NULL)
		return NULL;

	int i = 1;
	Node* t = head;
	Node* start = NULL;

	while(i < k && t){
		t = t->next;
		++i;
	}
	start = t->next;
	t->next = NULL;
	t= start;
	while(t->next)
		t = t->next;
	t->next = head;
	return start;

}

int main(){
	Node* h1 = NULL;
	for (int i = 6; i >=1; --i)
	{
		insertNode(&h1,i);
	}
	disp(h1);
	Node* head = rotateClockwise(h1,4);
	disp(head);
	return 0;
}
