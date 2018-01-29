//find the node with the lowest value in a BST
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

//inorder traversal of BST
void inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//finds the node with the lowest value
int lowestNode(Node *root)
{
    if(root==NULL)
        return INT_MIN;
	//if the node is the leftmost node
	if(root->left==NULL)
		return root->data;

	return lowestNode(root->left);
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

    //non-empty tree
    Node *root=createNode(5);
	insert(&root,3);
	insert(&root,8);
	insert(&root,2);
	insert(&root,4);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	cout<<"Inorder Traversal of tree 1:\n";
    inOrder(root);
    int result=lowestNode(root);
    if(result==INT_MIN)
        cout<<"\nTree is Empty\n";
    else
        cout<<"\nLowest Element:"<<result;


    //empty tree
    Node *root2=NULL;
    cout<<"\n\nInorder Traversal of tree 2:\n";
    inOrder(root2);
    result=lowestNode(root2);
    if(result==INT_MIN)
        cout<<"Tree is Empty\n";
    else
        cout<<"\nLowest Element:"<<result;

	return 0;
}
