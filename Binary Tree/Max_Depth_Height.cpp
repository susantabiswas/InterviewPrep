//get the maximum depth or height of a binary tree
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


//returns the maximum height of a binary tree
int getMaxDepth(Node* root){
	if(root == NULL)
		return 0;

	int lh = getMaxDepth(root->left);
	int rh = getMaxDepth(root->right);

	return max(lh,rh) + 1;
}
main(){
/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);

	cout<<getMaxDepth(root);	
}