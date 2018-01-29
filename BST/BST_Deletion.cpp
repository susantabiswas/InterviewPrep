//delete a key in BST

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

//preorder traversal
void preOrderTraversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

//for inserting node in BST
Node* insertNodeBST(Node* root, int key){
	if(root == NULL)
		return createNode(key);

	if( key > root->data)
		root->right = insertNodeBST(root->right, key);
	else if(key < root->data)
		root->left = insertNodeBST(root->left, key);
	return root;
}

//finds the inorder successor
Node* findInorderSuccessor(Node* root){
	while(root->left)
		root = root->left;
	return root;
}

//for deletion of node in BST
/*
	3 conditions are there:
	1> if the key is a leaf node then delete it
	2> if it has only one child then return that child in its place after deleting it
	3> if it has two children then return the inorder successor in its place and
	delete the inorder successor form its original location at the leaf position
*/
Node* deleteNodeBST(Node* root, int key){
	if(root == NULL)
		return NULL;

	//if the key is found
	if(root->data == key){
		//if it is a leaf node
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}
		//if it has only one child
		else if(!root->left || !root->right){
			Node* t = root->left?root->left:root->right;
			delete root;
			return t;
		}

		//if it has both the children,find the inorder successor
		else if(root->left && root->right){
			Node* succ = findInorderSuccessor(root->right);
			root->data = succ->data;
			root->right = deleteNodeBST(root->right,succ->data);
			return root;
		}
	}
	else if(key > root->data)
		root->right = deleteNodeBST(root->right, key);
	else
		root->left = deleteNodeBST(root->left, key);
	return root;
}

main(){
	Node* root = NULL;
	root = insertNodeBST(root,4);
	root = insertNodeBST(root,3);
	root = insertNodeBST(root,2);
	root = insertNodeBST(root,5);
	root = insertNodeBST(root,15);
	root = insertNodeBST(root,8);
	root = insertNodeBST(root,9);
	root = insertNodeBST(root,1);

	preOrderTraversal(root);
	cout<<endl;
	root = deleteNodeBST(root,3);
	preOrderTraversal(root);
	cout<<endl;
	root = deleteNodeBST(root,4);
	preOrderTraversal(root);
}
