//Merge sort for linked list
//Merge 2 sorted linked lists
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


Node* mergeLists(Node* h1 ,Node* h2){
	if(!h1)
		return h2;
	if(!h2)
		return h1;
	Node* prev = NULL;
	Node* new_head = h1->data<h2->data?h1:h2;

	while(h1 && h2){
		if(h1->data < h2->data){
			if(prev != NULL){
				prev->next = h1;
			}
			prev = h1;
			h1 = h1->next;
		}
		else{
			if(prev != NULL){
				prev->next = h2;
			}
			prev = h2;
			h2 = h2->next;
		}
	}

	if(h1)
		prev->next = h1;
	if(h2)
		prev->next = h2;

	return new_head;
}

Node* mergeSort(Node* head){

	if(head == NULL || head->next == NULL)
		return head;

	//find the tail node and mid node
	Node* fast = head;
	Node* slow = head;
	Node* prev = NULL;
	while(fast && fast->next && slow){
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}

	//separate the two lists
	prev->next = NULL;
	Node* left = mergeSort(head);
	Node* right = mergeSort(slow);
	Node* res = mergeLists(left,right);
	return res;
}

int main(){
	Node* h1 = NULL;
	insertNode(&h1,9);
	insertNode(&h1,7);
	insertNode(&h1,14);
	insertNode(&h1,3);
	insertNode(&h1,1);
	insertNode(&h1,65);
	insertNode(&h1,5);
	insertNode(&h1,13);
	insertNode(&h1,2);

	disp(h1);

	Node* res = mergeSort(h1);
	disp(res);
	return 0;
}
