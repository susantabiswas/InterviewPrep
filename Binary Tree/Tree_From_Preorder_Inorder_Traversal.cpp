//Create a tree from given inorder and preorder traversal
#include<iostream>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	char data;
};

class tree
{
private:
	Node *root;
public:
	Node*createNode(int data);
	Node* createTree(char in[],int start,int end,char pre[],int index);
	void inOrder(Node*);
};

//Inoder Traversal
void tree::inOrder(Node *root)
{
	if(root==NULL)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}
//for creating the node
Node* tree::createNode(int data)
{
	try
	{
		Node *node=new Node;
		if(node)
		{
			node->left=NULL;
			node->right=NULL;
			node->data=data;

		}
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory error!\n";
		return NULL;
	}
}


//creates a tree from inorder and preorder traversal
/*Since left most node in preorder traversal is the root node of tree,then we use this
node to look this node up in the inorder list and find out about the left and right subtrees.
Follow the above steps for the rest of the nodes
*/
// start:it denotes the starting position of the inorder list
//	end:denotes the end index of the inorder list
//	index:denotes the current root of tree(the first index of preorder list for a given subtree)

Node* tree::createTree(char in[],int start,int end,char pre[],int index)
{
	//when the node is a leaf node
	if(start>end)
		return NULL;

	for (int i = start; i <= end; ++i)
	{
		if(in[i]==pre[index])
		{
			Node *root =createNode(in[i]);
			root->left=createTree(in,start,i-1,pre,index+1);
			root->right=createTree(in,i+1,end,pre,(i-start)+index+1);

			return root;
		}
	}
}

int main()
{
	char pre[]={'A','B','D','E','C','F'};
	char in[]={'D','B','E','A','F','C'};

	int n=sizeof(pre)/sizeof(char);

	tree ob;
	Node *root=ob.createTree(in,0,n-1,pre,0);
	cout<<"Inorder Traversal:\n";
	ob.inOrder(root);

	return 0;
}
