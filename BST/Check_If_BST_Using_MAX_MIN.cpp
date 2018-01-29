//check whether the tree is BST
#include<iostream>
#include<limits>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
};

//creates node
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->left = node->right = NULL;
		node->data = data;
		return node;
	}
	return NULL;
}

//check if BST using MIN and MAX limits
/*
	We set and impose limits for the values that can exist for the nodes
	on going down the left subtree the MAX value it its parent,
	on going down the right subtree MIN value is its parent
	if these are not satisfied then it is not a BST
*/
bool isBST(Node* root, int MIN, int MAX){
	if(root == NULL)
		return true;

	if(root->data < MIN || root->data >MAX)
		return false;

	return ( isBST(root->left, MIN, root->data-1) && isBST(root->right, root->data+1, MAX));
}

bool isBSTDriver(Node* root){
	int MAX = numeric_limits<int>::max();
	int MIN = numeric_limits<int>::min();
	return isBST(root, MIN, MAX);
}

main(){
/*				4
			  /   \
			 2     5
			/ \
		  1   3
*/
	Node *root=createNode(4);
	root->right=createNode(5);
	root->left=createNode(2);
	root->left->left=createNode(1);
	root->left->right=createNode(3);

	cout<<isBSTDriver(root);
}
