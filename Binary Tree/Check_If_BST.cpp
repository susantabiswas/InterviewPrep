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

bool isBST(Node *root,int max,int min){
	if(root==NULL)
		return true;
	if(root->data<min || root->data>max)
		return false;
	return isBST(root->left,root->data,min) && isBST(root->right,max,root->data);

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
