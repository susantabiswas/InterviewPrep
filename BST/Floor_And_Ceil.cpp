//Find the Floor and Ceil of a given key from the BST
/*
	Floor: It is that node which is equal to or nearest minimum of key
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


//finds the floor and Ceil of a given key
void  findFloorCeil(Node *root,int key,int &f,int &c)
{
	if(root==NULL)
		return ;

	if(root->data==key)
	{
		f=key;
		c=key;
		return;
	}

	//when the key is lesser than root then for ceil go left till equal or nearest maximum is found
	else if(root->data>key)
	{
		if(root->data<c)
			c=root->data;
		findFloorCeil(root->left,key,f,c);
	}

	//when the key is greater than root then for floor go right till equal or nearest maximum is found
	else if(root->data<key)
	{
		if(root->data>f)
			f=root->data;
		findFloorCeil(root->right,key,f,c);
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
    	f=INT_MIN;
		c=INT_MAX;
        findFloorCeil(root,i,f,c);
    	cout<<"Key:"<<i<<" Floor:"<<f<<" Ceil:"<<c<<endl;
    }
	return 0;
}
