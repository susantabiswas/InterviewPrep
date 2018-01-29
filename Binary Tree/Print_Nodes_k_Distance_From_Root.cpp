//Print all the nodes which are at 'k' distance from the root
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

//creates node for the tree
Node *create(int data)
{
	try{
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

//for getting the width of a particular level
void printNodes(Node *root,int k)
{
	if(root==NULL)
		return ;
	if(k==1)
		cout<<root->data<<" ";

	else if(k>1)
		printNodes(root->left,k-1);
		printNodes(root->right,k-1);
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	cout<<"Nodes at 'k' distance :";
	printNodes(root,2);
	return 0;

}
