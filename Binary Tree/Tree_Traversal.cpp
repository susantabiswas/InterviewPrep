//Binary Tree Traversal DFS:Preorder,Inorder,Postorder
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

//postorder traversal
void preOrder(Node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);

}

//Inoder Traversal
void inOrder(Node *root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}
//Postorder traversal

void postOrder(Node *root)
{
	if(root==NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}
int main()
{
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	cout<<"Preorder\n";
	preOrder(root);
	cout<<"\nInorder\n";
	inOrder(root);
	cout<<"\nPostorder\n";
	postOrder(root);
	return 0;
}
