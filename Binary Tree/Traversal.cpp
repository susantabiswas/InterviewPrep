//Tree traversal
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

//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

}

//preorder traversal
void preOrderTraversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

//post order traversal
void postOrderTraversal(Node* root){
	if(!root)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";

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

	preOrderTraversal(root);
	cout<<endl;
	inOrderTraversal(root);
	cout<<endl;
	postOrderTraversal(root);
	cout<<endl;
}
