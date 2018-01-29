//connects all the adjacent nodes which lie at the same level

/*Here nextRight pointer has been used to connect to the adjacent node lying in the same level.
  Traverse eack level and store each node of that level in a list,then during enqueing if the list contains a
  node previous to the one being tried to insert ,then make the nextRight of the last inserted node point to the current node*/

#include<iostream>
#include<list>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *nextRight;
};

list<Node*> l;
//creates node for the tree
Node *create(int data)
{
	try{
		Node *node=new Node;
		node->data=data;
		node->left=NULL;
		node->right=NULL;
		node->nextRight=NULL;

		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory overflow!!";
		return NULL;
	}
}

//finds the height of binary tree
int getHeight(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+ max(getHeight(root->left),getHeight(root->right));
}

//for traversing a particular level
void traverseLevel(Node *root,int level)
{
	if(root==NULL)
		return ;
	//reached the level
	if(level==1)
	{
		//check if the previous adjacent node is present or not
		if(l.size()!=0)
		{
			(l.back())->nextRight=root;
		}
		l.push_back(root);
	}

	else if(level>1)
	  traverseLevel(root->left,level-1);
	  traverseLevel(root->right,level-1);
}

//connects the adjacent nodes lying in the same level
void connectNodes(Node *root)
{
	if(root==NULL)
		return ;

	int h=getHeight(root);

	//loop through all the levels and connect the adjacent nodes
	for (int i = 1; i <=h; ++i)
	{
		traverseLevel(root,i);
        l.clear();
	}

}

int main()
{
	/*
			1
           /  \
          2		3
         / \     \
        4   5      6 
	
	*/
	Node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->right->right=create(6);
	root->left->right=create(5);

	connectNodes(root);
	
	return 0;

}
