//create an AVL tree with given height 'h' or HB(0) tree i.e,height difference 0

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


///creates a tree with given height 'h'
Node* buildTree(int h){
	static int c=0;
	if(h==-1){
		return NULL;
	}
	//create a node
	Node *node=createNode(c++);
	node->left=buildTree(h-1);
	node->right=buildTree(h-1);

	return node;
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

	Node* root=buildTree(4);
	display(root);
	return 0;
}
