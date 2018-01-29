//Preorder traversal of binary tree using iterative method.Stack has been used
#include<iostream>
#include<list>
using namespace std;

struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
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

//preorder traversal using iteration
void preOrder(Node *root)
{
		//stack for storing the elements during DFS
		list<Node*> stack;
		Node *current=root;
		Node *temp=NULL;
		stack.push_front(current);
		while(stack.size()>0)
		{
			//go till the last left node
			while(current!=NULL)
			{
				stack.push_front(current);
				cout<<current->data<<" ";
				current=current->left;
			}
			//when the last left node is NULL,then print the first element of stack and go to right child of it

			//pop the element
			current=stack.front();
			stack.pop_front();

			current=current->right;
		}

}


int main()
{
	//tree creation
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	preOrder(root);

	return 0;
}
