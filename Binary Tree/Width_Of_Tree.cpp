//finds thw width of a binary tree
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
int getWidth(Node *root,int level)
{
	if(root==NULL)
		return 0;
	if(level==1)
		return 1;
	else if(level>1)
		return getWidth(root->left,level-1)+getWidth(root->right,level-1);
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	cout<<"Width:"<<getWidth(root,1)<<endl;
	return 0;

}
