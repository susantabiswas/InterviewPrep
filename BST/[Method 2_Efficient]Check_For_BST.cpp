//check whether a given  tree is BST or not
/*
now a binary tree is a BST ,if :
all the nodes in its left subtree are lesser than the root
and all the noes in the right subtree are greater than the root
solution:for each node check if the highest value of its left subtree is lesser than it or not
		 for each node check if the lowest value of its right subtree is greater than it or not
		 Here instead  of traversing through repeated nodes we instead use limiting values for checking
NOTE:works for integer values
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
bool isBST(Node *root,int min,int max)
{
	if(root== NULL)
		return true;

	//if the current node in left subtree is greater than the previous node and
	//if the current node in right subtree is lesser than the root node then return false
	if( root->data<min || root->data>max)
		return false;

    //check for the left and right child
    return isBST(root->left,min,(root->data)-1) && isBST(root->right,1+(root->data),max);

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
	root->left->right=create(44);
    root->left->left->left=create(1);
    root->right->left=create(6);

	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    if(isBST(root,INT_MIN,INT_MAX))
    	cout<<"BST !\n";
    else
    	cout<<"Not a BST !\n";

	return 0;
}
