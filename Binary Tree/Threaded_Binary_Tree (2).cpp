//Inorder traversal using Morris Traversal based on Threaded Binary Tree
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

//inorder traversal using morris traversal
/*
	if the curr node has a right child only then
		print the node
		go to the right child

	else if it has a left child then:
		find the inorder predecessor by going to the rightmost child of left
		subtree.We visit each node twice ,on the second visit revert it back

		if the rightmostchild->right == NULL
			rightmostchild->right = curr

		else if the rightmostchild->right != NULL
			rightmostchild->right = NULL
			curr = curr->right

		go to the left child
*/
void inOrderMorrisTraversal(Node* root){
	if(root == NULL)
		return;

	Node* pred = NULL;

	while(root){
		//check if there is any left child or not
		//if it doesn't then just go right
		if(root->left == NULL){
			cout<<root->data <<" ";
			root = root->right;
		}
		//now we need to make the rightmost node of left subtree point to
		//the current node
		else if(root->left){
			pred = root->left;
			//find the rightmost node
			while(pred->right && pred->right != root){
				pred = pred->right;
			}

			//if the rightmost node hasn't been modified yet
			//make it point to the current node
			if(pred->right == NULL){
				pred->right = root;
				root = root->left;
			}
			//if the right points to the current node then revert it back
			else if(pred->right == root){
				cout<<root->data<<" ";
				pred->right = NULL;
				root = root->right;
			}
		}
	}
}

main(){
	/*			1
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

	inOrderMorrisTraversal(root);
}
