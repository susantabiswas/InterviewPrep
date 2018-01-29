//Inorder traversal using Moore Traversal.
/*this method doesn't require stack and is non-recursive.
Makes a tree a temporarily a threaded binary tree
then it reverts it back to its original form*/
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

//inorder traversal using moore traversal method
void mooreTraversal(Node *root)
{
	if(root==NULL)
		return;

	Node *pre=NULL;

	while(root!=NULL)
	{
		//if there is no child go to the right child 
		if(root->left==NULL)
		{
			cout<<root->data<<" ";
			root=root->right;
		}

		else
		{	
			//if it has a left child then traverse to the rightmost node of the left child
			pre=root->left;
			while(pre->right!=NULL && pre->right!=root)
				pre=pre->right;
			//if it doesn't point to its successor then make it point
			if(pre->right==NULL)
			{
				pre->right=root;
				root=root->left;
			}
			//if it is already pointing to the successor then revert it back 
			else
			{
				cout<<root->data<<" ";
				pre->right=NULL;
				root=root->right;
			}
		}
	}
}

int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	mooreTraversal(root);
	return 0;
}1
