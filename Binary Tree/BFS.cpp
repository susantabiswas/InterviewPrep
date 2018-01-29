//BFS traversal of a binary tree
#include<iostream>
#include<list>
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

//level order reversal of binary tree
void levelOrder(Node *root)
{
	list<Node*> queue;
	Node *current=root;

	if(current==NULL)
		return;

	//store the nodes sequentially according to their level and keep on storing
	//it the queue
	while(1)
	{
		cout<<current->data<<" ";

		if(current->left)
			queue.push_back(current->left);
		if(current->right)
			queue.push_back(current->right);

		current=queue.front();
		queue.pop_front();

		if(queue.size()==0)
			break;
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

	levelOrder(root);
	return 0;
}
