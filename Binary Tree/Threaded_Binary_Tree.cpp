//Threaded Binary tree
/*the right child of leaf node points to the inorder successor */

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	bool rightThread=false;
};

//creates node for the tree
Node *create(int data)
{
	try{
		Node *node=new Node;
		node->data=data;
		node->left=NULL;
		node->right=NULL;
		node->rightThread=false;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory overflow!!";
		return NULL;
	}
}

//for traversal to the leftmost node
Node* leftMostTraversal(Node *root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}


//traversal of a threaded binary tree
void traversal(Node *root)
{
	Node *current=leftMostTraversal(root);
	while(current!=NULL)
	{
		cout<<current->data<<" ";

		//if it is a leaf node ,go to the inorder successor
		if(current->rightThread)
			current=current->right;
		//else traverse further
		else
			current=leftMostTraversal(current->right);
	}
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->left->right=root->left;
	(root->left->left)->rightThread=true;
	root->right->right=create(6);
	root->right->right->rightThread=true;
	root->left->right=create(5);
	root->left->right->right=root;
	(root->left->right)->rightThread=true;

	traversal(root);
	return 0;
}
