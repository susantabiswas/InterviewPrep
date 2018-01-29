//Two nodes in the BST are swapped from their correct position.Correct their positions
/*Since inorder traversal gives ascending order,so traverse the BST and look for anomaly in the
list ,store it and look for the second anomaly,then swap them.*/

#include<iostream>
#include<climits>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
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



//Inoder Traversal
void inOrder(Node *root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}

//finds and stores the wrong positions in the BST during the traversal.
/*first:stores the first wrong position
 middle:stores the position just after first .For the case when the adjacent nodes are swapped
 last:stores the last wrong position
 During traversal "previous" stores the previous node ,if the previous node is greater than 
 that node is swapped ,make it first then if we again find this then this time the current 
 node is swapped ,store it
 */
void correctSwapped(Node *root,Node* &first,Node* &middle,Node* &last)
{
	//for storing the previous node's data
	  static Node *previous=NULL;

	  if(root==NULL)
		return;

	  correctSwapped(root->left,first,middle,last);

		if(previous==NULL)
			previous=root;
		else if(previous->data<root->data)
			previous=root;
		else
		{
			if(previous->data>root->data)
			 {
				if(first==NULL)
				{
					first=previous;
					previous=root;
					middle=root;
				}
				//second anomaly
				else
					last=root;
			}
		}
	}
	else
		return;

	correctSwapped(root->right,first,middle,last);
}

void fixBST(Node *root)
{
	Node *first=NULL;
	Node *middle=NULL;
	Node *last=NULL;

	correctSwapped(root,first,middle,last);

	int swap;
	//when adjacent nodes are swapped
	if(!last)
	{
		swap=first->data;
		first->data=middle->data;
		middle->data=swap;
	}
	//when non-adjacent nodes are swapped
	else
	{
		swap=first->data;
		first->data=last->data;
		last->data=swap;
	}
}

int main()
{
	/*
				 5
           /   \
          3		 8
         / \    / \
        2   9  6    4
	   /
	  1

	*/

	Node *root=create(5);
	root->left=create(3);
	root->right=create(8);
	root->left->left=create(2);
	root->right->right=create(4);
	root->left->right=create(9);
    root->left->left->left=create(1);
    root->right->left=create(6);

	cout<<"Inorder Traversal before Correction:\n";
    inOrder(root);
    cout<<endl;


	cout<<"Inorder Traversal after Correction:\n";
    fixBST(root);
    inOrder(root);
}
