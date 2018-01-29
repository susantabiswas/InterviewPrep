 //find the Floor of a key from BST
 /*
	Floor: It is that node which is equal to or nearest minimum of key
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


//finds the floor of a given key
/*Go on till you find a value equal to key .Meanwhile if there is a node whose value is lesser store it
and keep only the maximum of the lower value,this will be returned incase key is absent in the BST
*/
void  findFloor(Node *root,int key,int &f)
{
	if(root==NULL)
		return ;

	if(root->data==key)
	{
		f=key;
		return;
	}

	//go till a match is found or there is a node data lesser than key
	else if(root->data>key)
	{
		findFloor(root->left,key,f);
	}

	//go to find a match or for finding the nearest minimum
	else if(root->data<key)
	{
		if(root->data>f)
			f=root->data;
		findFloor(root->right,key,f);
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

    for (int i = 0; i < 16; ++i)
    {
    	f=INT_MIN;

        findFloor(root,i,f);
    	cout<<"Key:"<<i<<" Floor:"<<f<<endl;
    }
	return 0;
}
