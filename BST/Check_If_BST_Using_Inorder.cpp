//check whether the tree is BST or not using inorder traversal
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

//check if BST using inorder traversal
bool isBST(Node* root,Node* prev){
	if(root == NULL)
		return true;


	bool l = isBST(root->left, prev);

	//check if the previous element was smaller or not in inorder traversal
	if(prev){
		if(root->data < prev->data)
			return false;
	}
	prev = root;

	bool r = isBST(root->right, prev);
	if( l && r)
		return true;
	else
		return false;
}

bool isBSTDriver(Node* root){
	Node* prev = NULL;
	return isBST(root, prev);
}

main(){
/*				4
			  /   \
			 2     5
			/ \
		  1   3
*/
	Node *root=createNode(4);
	root->right=createNode(-5);
	root->left=createNode(2);
	root->left->left=createNode(1);
	root->left->right=createNode(3);

	cout<<isBSTDriver(root);
}
