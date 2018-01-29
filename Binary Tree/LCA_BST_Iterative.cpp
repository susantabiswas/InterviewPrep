//find the LCA of a and b in BST where  a<b
//without using recursion
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

//finds LCA in BST
/* 
	first node lying between a and b is the LCA
*/
int LCA(Node *root,int a,int b){
	if(root==NULL)	//when there is no LCA available
		return 0;
	while(root){
		if(root->data>a && root->data<b)
			return root->data;
		else if(root->data<a && root->data<b)
			root=root->right;
		else if(root->data>a && root->data>b)
			root=root->left;
	}
	return 0;		//when no LCA found
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
/*				3
			  /   \
			 -2     5
			/ \
		  -3   1
*/
	Node *root=createNode(3);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	root->left->right=createNode(1);

	cout<<"LCA:"<<LCA(root,-3,1);
	return 0;
}
