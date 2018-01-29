//insertion sort for linked list
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->data = data;
		node->next = NULL;
		return node;
	}
	return NULL;
}

//for inserting a node in its correct pos
Node* insertSorted(Node* head, Node* node){
	if(node == NULL)
		return NULL;
	if(head == NULL){
		node->next = NULL;
		return node;
	}

	Node* prev = NULL;
	Node* t = head;
	while(head && head->data < node->data){
		prev = head;
		head = head->next;
	}

	//first node is greater than the current node
	if(prev == NULL){
		node->next = head;
		return node;
	}
	node->next = head;
	prev->next = node;
	return t;
}

//for insertion sort
Node* insertionSort(Node* &head){
	Node* sort_head = NULL;
	Node* nextptr = NULL;
	//traverse the list and for each node insert it in its correct pos
	while(head){
		nextptr = head->next;
		sort_head = insertSorted(sort_head,head);
		head = nextptr;
	}
	head = sort_head;
}


/**
 Create a list for storing the sorted elements
 for each element see where that can be placed in the new list
 */
 
void sortedPos(Node* &head, Node* node){
    if(node == NULL)
        return;
    node->next = NULL;
    if(head == NULL ){
        head = node;
        return;
    }
    
    Node* prev = NULL;
    Node* t = head;
    
    while(t && t->val < node->val){
        prev = t;
        t = t->next;
    }
    if(prev == NULL){
        node->next = head;
        head = node;
    }
    else{
        node->next = t;
        prev->next = node;
    }
}

Node* insertionSort(Node* A) {
    Node* sorted = NULL;
    Node* t = A;
    Node* nextptr = NULL;
    while(t){
        nextptr = t->next;
        sortedPos(sorted,t);
        t = nextptr;
    }
    return sorted;
}

//for display
void disp(Node* head){
	while(head){
		cout<< head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	Node* head = createNode(3);
	head->next = createNode(2);
	head->next->next = createNode(6);
	head->next->next->next = createNode(5);
	head->next->next->next = createNode(51);
	head->next->next->next->next = createNode(2);

	disp(head);
	insertionSort(head);
	disp(head);
}
