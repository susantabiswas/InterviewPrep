
//create a BST .Insert elements in it

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

//displays the tree using inorder traversal
void display(Node *root){
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" " ;
	display(root->right);
}

int main(){
/*				4
			  /   \
			 2     5
			/ \
		   1   3
*/

	Node *root=createBST(NULL,1);
	createBST(root,3);
	createBST(root,2);
	createBST(root,5);
	createBST(root,4);

	display(root);
	return 0;
}
