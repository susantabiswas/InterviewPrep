//Find the lowest common ancestor of two given nodes in a BST
/*the two numbers lie either on different sides of lowest common ancestor or they lie on the same hierarchical line
 NOTE:Assuming that both the numbers exists in the BST and both are distinct numbers.
*/

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

//finds the lowest common ancestor of two given numbers n1 and n2 in a BST
/*the two numbers lie either on different sides of lowest common ancestor or they lie on the same hierarchical line
*/
Node* lowestCommonAncestor(Node *root,int n1,int n2)
{
    //keeps track of lowest ancestor node
	static Node *ancestor=NULL;

    //when both the numbers are on the same side then the node just preceding them on hierarchical line is the LCA.
	if(root==NULL)
		return ancestor;

	//when both the numbers are on different sides of root,then that is the lowest common ancestor
	if(((n1< root->data) && (n2> root->data) )|| ((n1> root->data) && (n2< root->data)))
	{
	    ancestor=root;
		return ancestor;
	}

	//when both the numbers are on the left side of root
	if(n1<root->data && n2<root->data)
	{
	    ancestor=root;
		lowestCommonAncestor(root->left,n1,n2);
	}

	//when both the numbers are on the left side of root
	if(n1>root->data && n2>root->data)
    {
        ancestor=root;
        lowestCommonAncestor(root->right,n1,n2);
    }

    else
        return ancestor;
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

    cout<<"\nLowest Common Ancestor:";
    //Node *
    Node *result=lowestCommonAncestor(root,13,9);

    if(result)
    	cout<<result->data<<endl;
    else
    	cout<<"No common ancestor\n";

	return 0;
}
