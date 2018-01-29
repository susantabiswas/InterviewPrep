//Finds the height or depth of a binary tree
//create a simple tree
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

//creates a node
Node* create(int data)
{
	try
	{
		Node *node=new Node;
		node->data=data;
		node->left=NULL;
		node->right=NULL;

		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory overflow!!";
		return NULL;
	}

}

//finds the height of binary tree
int height(Node *root)
{
	if(root==NULL)
		return 0;

	return 1+max(height(root->left),height(root->right));
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	cout<<"Height:"<<height(root);
	return 0;
}
