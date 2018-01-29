//search element in BST
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
Node* SearchNodeBST(Node *root,int key){
	if(root==NULL)
		return NULL;
	if(key<root->data)
		return SearchNodeBST(root->left,key);
	else if(key>root->data)
		return SearchNodeBST(root->right,key);
	else if(key==root->data)
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

	Node *root=createBST(NULL,4);
	createBST(root,2);
	createBST(root,3);
	createBST(root,5);
	createBST(root,1);

	//display(root);

	Node *t=SearchNodeBST(root,2);
	if(t)
		cout<<"element:"<<t->data;
	else
		cout<<t;
	return 0;
}
