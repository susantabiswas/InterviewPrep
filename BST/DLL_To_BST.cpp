//convert a DLL to BST
/*
	can be done in 2 ways :
	1. recursively create the trees by finding the midpoint of the linked list in
	each pass,TC:O(nlogn) ,we need to find the mid point each time for the linked list
	2.create tree from the leaf nodes TC:O(n)
*/
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

//for display
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//for node creation
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		return node;
	}
	else
		return NULL;
}

//for insertion in end
void insertEnd(Node** head,int data){
	Node *node = createNode(data);
	Node* t = *head;
	if(*head == NULL)
		*head = node;
	else{
		while(t->next){
			t = t->next;
		}
		t->next = node;
		node->prev = t;
	}
}

//for traversal
//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->prev);
	cout<<root->data<<" ";
	inOrderTraversal(root->next);

}

//for converting DLL to BST
Node* convertToBST(Node* &head,int c){
	if(c <= 0)
		return NULL;
	Node* l = convertToBST(head,c/2);

	Node* root = head;
	head = head->next;
	//make the previous subpart as the left subtree
	root->prev = l;

	root->next = convertToBST(head,c - c/2-1);
	return root;
}

//driver for converting the DLL to BST
Node* convertToBSTDriver(Node* root){
	int c = 0;

	//find the total nodes in the linked list
	Node* t = root;
	while(t){
		++c;
		t = t ->next;
	}
	return convertToBST(root, c);
}

main(){
	Node* head = NULL;
	insertEnd(&head,1);
	insertEnd(&head,2);
	insertEnd(&head,3);
	insertEnd(&head,4);
	insertEnd(&head,5);
	insertEnd(&head,6);
	insertEnd(&head,7);
	insertEnd(&head,8);
	disp(head);

	Node* root = convertToBSTDriver(head);
	inOrderTraversal(root);
}
