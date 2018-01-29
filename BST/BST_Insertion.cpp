//insert keys in BST
/*
	A new node is always inserted at a leaf position
*/
#include<iostream>
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

//Inserts a node in the BST
Node* insertNodeBST(Node* root, int key){
	//if we have reached the leaf position
	if(root == NULL)
		return createNode(key);

	//tarverse towards the correct direction
	if(key > root->data)
		root->right = insertNodeBST(root->right, key);
	else if(key< root->data)
		root->left = insertNodeBST(root->left, key);
	return root;
}

//for traversal
//preorder traversal
void preOrderTraversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

main(){
	Node* root = NULL;
	root = insertNodeBST(root,4);
	root = insertNodeBST(root,3);
	root = insertNodeBST(root,2);
	root = insertNodeBST(root,5);
	root = insertNodeBST(root,6);

	preOrderTraversal(root);
}
