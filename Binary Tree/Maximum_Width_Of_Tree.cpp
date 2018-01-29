//find the maximum width of a binary tree
/*find the height of tree,then go through each level and find the maximum width*/
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

//finds the height of binary tree
int getHeight(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+ max(getHeight(root->left),getHeight(root->right));
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

//finds the maximum width of the binary tree
int getMaxWidth(Node *root)
{
	if(root==NULL)
		return 0;

	int h=getHeight(root);
	int maxWidth=0;
	int width=0;

	//loop through all the levels and find their widths and compare them
	for (int i = 1; i <=h; ++i)
	{
		width=getWidth(root,i);
		if(width>maxWidth)
		maxWidth=width;
	}
	return maxWidth;
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	cout<<"Maximum Width:"<<getMaxWidth(root)<<endl;
	return 0;

}
