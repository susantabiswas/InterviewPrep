//check whether a given  tree is BST or not
/*
now a binary tree is a BST ,if :
all the nodes in its left subtree are lesser than the root
and all the noes in the right subtree are greater than the root
solution:Inorder traversal of a BST gives a sorted list of elements in ascending order
so check if the list is ascending or not
*/

#include<iostream>
#include<climits>
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
		cout<<"Memory Full !\n";
		return NULL;
	}
}

//checks whether a tree is BST or not
bool isBST(Node *root)
{
	if(root== NULL)
		return true;

	static int previous;

	isBST(root->left);

	if(root->data<=previous)
	{
		return false;
	}
	else
		previous=root->data;

	isBST(root->right);
}

//inorder traversal of BST
void inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
	/*This is not a BST
			 5
           /   \
          3		8
         / \   /  \
        2  44  6   9
	   /
	  1

	*/

	Node *root=create(5);
	root->left=create(3);
	root->right=create(8);
	root->left->left=create(2);
	root->right->right=create(9);
	root->left->right=create(4);
    root->left->left->left=create(1);
    root->right->left=create(6);

	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    if(isBST(root))
    	cout<<"BST !\n";
    else
    	cout<<"Not a BST !\n";

	return 0;
}
