//check whether a given tree S is a subtree of another tree T or not
#include<iostream>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
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

//checks whether all the descendents of tree2 are present in tree 1 or not
bool isSubtree(Node *root1,Node *root2)
{
	if(root1==NULL)
		return true;
	if(root2==NULL)
		return true;

	if(root1->data==root2->data)
        return isSubtree(root1->left,root2->left) && isSubtree(root1->right,root2->right);
    else
        return false;

}

//for traversal of tree
bool traverse(Node *root1,Node *root2)
{
	if(root1==NULL)
		return false;

	if(root1->data==root2->data)
	{
		if(isSubtree(root1,root2))
            return true;
		else
            return false;

	}

    return traverse(root1->left,root2) || traverse(root1->right,root2);

}

int main()
{
	/*
		tree 1
			1
           /  \
          2		3
         / \     \
        4   5      6

	*/
	Node *root1=create(1);
	root1->left=create(2);
	root1->right=create(3);
	root1->left->left=create(4);
	root1->right->right=create(6);
	root1->left->right=create(5);

	/*
		tree 2
			2
           /  \
          4		5
   */
	Node *root2=create(2);
	root2->left=create(4);
	root2->right=create(5);

	if(traverse(root1,root2))
        cout<<"Subtree\n";
    else
        cout<<"Not a subtree\n";
	return 0;
}
