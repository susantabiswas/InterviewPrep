//given a key ,print all its ancestors
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

//prints the ancestors of a node
bool printAncestors(Node* root, int key){
	if(!root)
		return false;
	if(root->data == key)
		return true;

	bool l = printAncestors(root->left, key);
	bool r = printAncestors(root->right, key);
	if(l || r){
		cout<<root->data<<" ";
		return true;
	}
	return false;
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

	printAncestors(root ,4);
}
