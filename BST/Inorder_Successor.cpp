// find the inorder successor of a node
/* if Right Subtree exist:
	Inorder successor is the leftmost node of right subtree
else
	it is  that last ancestral node whose left child is an ancestor of the key
*/
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
		cout<<"Memory Full !\n";
		return NULL;
	}
}

//creates a BST
void insert(Node **root,int key)
{
	//when the BST is empty
	if(*root==NULL)
	{
		(*root)=create(key);
		return;
	}

	//when the key is already present
	if((*root)->data==key)
		return;

	//search for the appropriate position for the key
	//if the key is less than root ,go left
	//else go right
	if((*root)->data>key)
		insert(&((*root)->left),key);
	else
		insert(&((*root)->right),key);

}

//finds the minimum value of a tree
Node* minVal(Node*root)
{
	if(root==NULL)
		return NULL;

	while(root->left)
	{
		root=root->left;
	}
	return root;
}

//searches and returns the key in the BST
Node* search(Node *root,int key)
{
	if(root==NULL)
		return NULL;

	if(root->data==key)
		return root;
	else if(root->data>key)
		return search(root->left,key);
	else if(root->data<key)
		return search(root->right,key);
	else
		return NULL;

}

//finds the successor of a node
Node* successor(Node *root,int key)
{
	//when the tree is empty
	if(root== NULL)
		return NULL;

	Node *temp=search(root,key);

	//if the key is not present
	if(temp==NULL)
		return NULL;
	else
	{
		//if the right subtree is not empty then the minimum value of right subtree is the successor
		if(temp->right)
			return minVal(temp->right);

		//it is that last node whose left child is an ancestor of key
		//start traversal from the top root
		else
		{
			 Node *succ=NULL;
			 while(root)
			 {
			 	if(key<root->data)
			 	{
			 		succ=root;
			 		root=root->left;
			 	}
			 	else if(key>root->data)
			 	{
			 		root=root->right;
			 	}
			 	else
			 		break;
			 }
			 return succ;
		}
	}
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
	/*
			 5
           /   \
          3		8
         / \    / \
        2   4  6    9
	   /
	  1

	*/

	Node *root=create(5);
	insert(&root,3);
	insert(&root,8);
	insert(&root,2);
	insert(&root,4);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);
	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    Node *result=successor(root,8);

    if(result)
    	cout<<"Successor:"<<result->data;
    else
    	cout<<"Key not found  !\n";

	return 0;
}
