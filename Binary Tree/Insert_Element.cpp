//Insert an element into a tree
/*
 since it is not a BST just insert the node at the first leaf position
*/

#include<iostream>
using namespace std;

//node structure for tree node
struct Node{
	Node *left,*right;
	int data;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->data=data;
		return node;
	}
	else
		return NULL;
}

//displays the tree using inorder traversal
void display(Node *root){
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" " ;
	display(root->right);
}


//inserts a node into the tree using recursive method
bool insertElement(Node **root,int data){
	//if the tree is empty
	if((*root)==NULL){
		Node *node=createNode(data);
		*root=node;
		return true;
	}
	else if((*root)->left==NULL){
			Node *node=createNode(data);
			(*root)->left=node;
			return true;
	}
	else if((*root)->right==NULL){
			Node *node=createNode(data);
			(*root)->left=node;
			return true;
	}
	return (insertElement(&((*root)->left),data)||insertElement(&((*root)->right),data));
}

int main(){
/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);

	cout<<"Before: ";display(root);
	insertElement(&root,6);
	cout<<"\nAfter: ";display(root);
	return 0;
}
