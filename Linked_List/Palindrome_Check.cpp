//Check if the linked list is palindrome or not
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

bool isPalindrome(Node* head){
	if(head == NULL)
		return false;
	if(head->next == NULL)
		return true;
	int c =1;
	Node* t = head;
	while(t){
		++c;
		t = t->next;
	}

	t = head;
	int i =1;
	while(i<c/2 && t){
		i++;
		t = t->next;
	}

	t->next = reverseNodesRec(t->next);
	t = t->next;
	i = 1;
	while(i<=c/2 && head && t){
		if(t->data != head->data)
			return false;
		t = t->next;
		head = head->next;
	}
	return true;
}

int main(){
	Node* h1 = NULL;
	insertNode(&h1,9);
	insertNode(&h1,79);
	insertNode(&h1,4);
	//insertNode(&h1,13);
	insertNode(&h1,4);
	insertNode(&h1,7);
	insertNode(&h1,9);

	disp(h1);
	cout<<isPalindrome(h1);
	return 0;
}
