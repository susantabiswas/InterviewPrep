//search a key node in a BST
#include<iostream>
using namespace std;


//for making nodes of tree
struct Node
{
	int data;
	Node *left;
	Node *right;
};

//creates a node
Node* createNode(int data)
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
		(*root)=createNode(key);
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


//searches a key in the BST
bool search(Node *root,int key)
{
	if(root==NULL)
		return false;

	if(root->data==key)
		return true;
	else if(root->data>key)
		return search(root->left,key);
	else if(root->data<key)
		return search(root->right,key);
	else
		return false;

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
         / \   /  \
        2   4  6   9
	   /
	  1

	*/

	Node *root=createNode(5);
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

    if(search(root,4))
    	cout<<"Key Found !\n";
    else
    	cout<<"Key not Found !\n";

	return 0;
}
