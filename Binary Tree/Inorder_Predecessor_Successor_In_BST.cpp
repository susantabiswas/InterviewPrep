//find the inorder predecessor and successor of a node in BST .If the node is not found then
//return values within which it should exist
/*
	Inorder successor of a node :
	if it has right child then it is the min of the right subtree
	else if it doesn't have one then it is the last left ancestor

	Inorder predeccessor of a node :
	if it has left child then it is the max of the left subtree
	else if it doesn't have one then it is the last right ancestor

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

//creates a BST
Node* createBST(Node* root,int key){
	if(root==NULL){
		Node *node=createNode(key);
		return node;
	}

	if(root->data>key){
		root->left=createBST(root->left,key);
	}
	else if(root->data<key){
		root->right=createBST(root->right,key);
	}
	return root;
}

//search Node in BST
Node* searchNodeBST(Node *root,int key){
	if(root==NULL)
		return NULL;
	if(key<root->data)
		return searchNodeBST(root->left,key);
	else if(key>root->data)
		return searchNodeBST(root->right,key);
	else if(key==root->data)
		return root;
}


//finds the minimum
Node* findMin(Node *root){
	if(root==NULL)
		return NULL;
	if(root->left==NULL)
		return root;
	return findMin(root->left);
}


//finds the maximum
Node* findMax(Node *root){
	if(root==NULL)
		return NULL;
	if(root->right==NULL)
		return root;
	return findMax(root->right);
}


//finds inorder predecessor and successsor
void inorderPredSucc(Node *root,Node* &pre,Node* &succ,int key){
	if(root==NULL)
		return;
	if(root->data==key){		//when the key is found
		if(root->left )
			pre=findMax(root->left);
		if(root->right)
			succ=findMin(root->right);
		return;
	}
	else if(root->data>key){
		succ=root;
		return inorderPredSucc(root->left,pre,succ,key);
	}
	else if(root->data<key){
		pre=root;
		return inorderPredSucc(root->right,pre,succ,key);
	}
}

void inorderPredSuccDriver(Node*root,int key){
	if(root==NULL)
		return;
	Node *pre=NULL;
	Node *succ=NULL;
	inorderPredSucc(root,pre,succ,key);

	if(pre)
		cout<<"predecessor:"<<pre->data;
	if(succ)
		cout<<" successsor:"<<succ->data;
}

int main(){
/*				 5
			  /   \
			 2     6
			/ \
		   1   4
*/

	Node *root=createBST(NULL,5);
	createBST(root,2);
	createBST(root,4);
	createBST(root,6);
	createBST(root,1);

	inorderPredSuccDriver(root,3);
	return 0;
}
