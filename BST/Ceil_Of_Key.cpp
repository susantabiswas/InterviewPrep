//find the Ceil of a key from BST
/*
	Ceil: It is that node which is equal to or nearest maximum of key
*/

#include<iostream>
#include<climits>
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


//finds the Ceil of a given key
/*Go on till you find a value equal to key .Meanwhile if there is a node whose value is greater store it
and keep only the minimum of the greater values,this will be returned incase key is absent in the BST
*/void  findCeil(Node *root,int key,int &c)
{
	if(root==NULL)
		return ;

	if(root->data==key)
	{
		c=key;
		return;
	}

	//keep going left to find the data node with nearest maximum value
	else if(root->data>key)
	{
		if(root->data<c)
			c=root->data;
		findCeil(root->left,key,c);
	}

	//go till a node data greater than key is found
	else if(root->data<key)
	{
		findCeil(root->right,key,c);
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

    int f=INT_MIN;
    int c=INT_MAX;

    for (int i = 0; i < 16; ++i)
    {
		c=INT_MAX;
        findCeil(root,i,c);
    	cout<<"Key:"<<i<<" Ceil:"<<c<<endl;
    }
	return 0;
}
