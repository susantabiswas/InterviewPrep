//Quick sort on a doubly linked list
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

//for finding the last node
Node* findLast(Node* head){
	if(head == NULL)
		return NULL;
	while(head->next){
		head = head->next;
	}
	return head;
}

//memory errors checking skipped on purpose
Node* createNode(int data){
	Node* node = new Node;
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}

void insertNode(Node** head,int data){
	Node* node = createNode(data);
	if(*head == NULL){
		*head = node;
	}
	else{
		node->next = *head;
		(*head)->prev = node;
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
//for swapping elements
void swapData(Node* &a,Node* &b){
	int temp = 0;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

//for finding the pivot position
Node* partition(Node* l ,Node* h){
	Node* pivot = h;
	h = h->prev;

	Node* write = l;
	while(l && h && l!=h->next){

		if(l->data <= pivot->data){
			swapData(l,write);
			write = write->next;
		}
		l = l->next;
	}
	swapData(write,pivot);
	return write;
}

Node* quickSort(Node* l,Node* h){
	if(l!=h && l && h && l!=h->next){
		Node* pivot = partition(l,h);
		quickSort(l,pivot->prev);
		quickSort(pivot->next,h);
	}
	return l;
}

Node* quickSortDriver(Node* head){
	Node* last = findLast(head);
	return quickSort(head,last);
}

main(){
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

	Node* res = quickSortDriver(h1);
	disp(res);
	return 0;
}
