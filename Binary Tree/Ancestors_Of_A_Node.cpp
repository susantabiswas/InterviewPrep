//Print all the ancestors of a given node
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

//prints all the ancestors of a gievn key node
bool printAncestors(Node *root,int key)
{
	if(root==NULL)
		return false;

	if(root->data==key)
		return true;

	if(printAncestors(root->left,key)||printAncestors(root->right,key))
	{
		cout<<root->data<<" ";
		return true;
	}
	else
		false;
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	if(printAncestors(root,4));
	return 0;
}
