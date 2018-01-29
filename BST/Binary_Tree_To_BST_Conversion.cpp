//Convert a Binary Tree to BST
/*Solution: Traverse the tree and store the elements
			sort the array elements
			do inorder traversal of binary tree and replace the binary tree values with that of sorted array
            as inorder traversal of BST gives ascending order of elements.
*/

#include<iostream>
#include<list>
#include<algorithm>
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

//inorder traversal of BST
void inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//inorder traversal of BST while storing the elements of tree as well
void takeDataInOrder(Node *root,list<int> &l)
{
    if(root==NULL)
        return;

    takeDataInOrder(root->left,l);

    l.push_back(root->data);		//store the binary tree elements

    takeDataInOrder(root->right,l);
}


//inorder traversal of BST while replacing the data value of Binary Tree with sorted array data
void giveDataInOrder(Node *root,list<int> &l)
{
    if(root==NULL)
        return;

    giveDataInOrder(root->left,l);

    root->data=l.front();		//replace the binary tree elements with sorted data values
    l.pop_front();

    giveDataInOrder(root->right,l);
}

//converts a binary tree to BST
void convertToBST(Node *root)
{
    list<int> l;
	//traverse the binary tree
	takeDataInOrder(root,l);

	//sort the array elements
    l.sort();

    //replace the binary tree elements with sorted array elements
	giveDataInOrder(root,l);
}

int main()
{
	/*This is not a BST
			 8
           /   \
          3		5
         / \    / \
        4   1  6    2
	   /
	  9

	BST:
			 5
           /   \
          3		8
         / \    / \
        2   4  6    9
	   /
	  1

	*/

	Node *root=create(8);
	root->left=create(3);
	root->right=create(5);
	root->left->left=create(4);
	root->right->right=create(2);
	root->left->right=create(1);
    root->left->left->left=create(9);
    root->right->left=create(6);

	cout<<"Inorder Traversal before Making BST:\n";
	inOrder(root);
    cout<<endl;

    convertToBST(root);

    cout<<"\n\nInorder Traversal after Making BST:\n";
    inOrder(root);
    cout<<endl;

	return 0;
}
