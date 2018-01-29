//Find the 'k'th smallest node from BST.
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

//finds the 'k'th smallest node
/*Inorder traversal gives the nodes in ascending order so using that fact 'k' element can be found*/
void findKthSmallest(Node *root,int k)
{
    //for keeping count of the inorder traversal element
    static int count=0;
    //for not traversing the whole tree even after the kth node
    static int exit=0;

	if(root==NULL)
		return;

	if(!exit)
        findKthSmallest(root->left,k);

    //for each inorder traversal increment the counter and when it is equal to 'k' display the element and make exit =1
    ++count;
	if(count==k)
	{
	    cout<<root->data;
        return;
	}

	if(!exit)
        findKthSmallest(root->right,k);
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
			 8
           /   \
          5		11
         / \   /  \
        2   6  9   13
	   /
	  1

	*/

	Node *root=createNode(8);
	insert(&root,5);
	insert(&root,11);
	insert(&root,2);
	insert(&root,6);
	insert(&root,1);
	insert(&root,9);
	insert(&root,13);

	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    cout<<"\nK-th Smallest Node:";
    findKthSmallest(root,3);

	return 0;
}
