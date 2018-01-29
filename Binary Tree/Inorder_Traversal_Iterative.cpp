//Inorder traversal of binary tree using iterative method
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

//inorder traversal using iteration
void inOrder(Node *root)
{
		//stack for storing the elements during DFS
		list<Node*> stack;
		Node *current=root;

		stack.push_front(current);
		while(stack.size()>0)
		{
			//go till the last left node
			while(current!=NULL)
			{
				stack.push_front(current);
				current=current->left;
			}
			//when the last left node is NULL,then print the first element of stack and go to right child of it

			//pop the element
			current=stack.front();
			stack.pop_front();

			//root has been pushed twice so we see whether at least one element is there or not in the stack
			//when only one element is there ,that element must be the extra root that was pushed ,so we don't print it.
			if(stack.size()>0)
				cout<<current->data<<" ";

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

	inOrder(root);

	return 0;
}
