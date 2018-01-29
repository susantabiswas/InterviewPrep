
//check whether a tree is a BST or not

#include<iostream>
#include<climits>
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

//finds the maximum child of the left child
Node* maxChild(Node *root){
	if(root==NULL)
		return NULL;
	if(root->right=NULL)
		return root;

	return maxChild(root->right);
}

//finds the minimum child of the left child
Node* minChild(Node *root){
	if(root==NULL)
		return NULL;
	if(root->left=NULL)
		return root;

	return minChild(root->left);
}


//check if the tree is BST or not
/*
	here for each root we check whether the max value in the left subtree is lesser
	than the currnt root and the min value in the right subtree is greater than the current
	root

*/
int isBST(Node *root){
	if(root==NULL)
		return 0;

	Node* l=maxChild(root->left);
	Node* r=minChild(root->right);

	if(root->data<l->data || root->data>r->data)
		return 0;
	return isBST(root->left) && isBST(root->right);
}

//search node in a BST utility driver
bool isBSTUtil(Node *root){
	return isBST(root,INT_MAX,INT_MIN);
}

int main(){
/*				 1
			  /   \
			 -2     5
			/ \
		  -3    0
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	root->left->right=createNode(0);


	cout<<isBSTUtil(root);
	return 0;
}
