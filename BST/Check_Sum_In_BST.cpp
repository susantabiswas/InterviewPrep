//Check whether a number exist as a sum of two numbers in a BST

/*sol:Since inorder traversal of the BST gives a sorted array of elements ,so
 just like in array starting from front and end,we do in BST.Store the Max and Mix values ,
 then if target value if greater ,in the left subtree increase the value of min ,if the 
 target is smaller in the right subtree ,increase the value of Max,do above till max+min=target
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

//finds the maximum value of a tree
Node* maxVal(Node*root)
{
	if(root==NULL)
		return NULL;

	while(root->right)
	{
		root=root->right;
	}
	return root;
}


//finds the minimum value of a tree
Node* minVal(Node*root)
{
	if(root==NULL)
		return NULL;

	while(root->left)
	{
		root=root->left;
	}
	return root;
}

//checks whether the sum is present or not in the BST
//root1:for traversing and keeping track of left subtree
//root2:for traversing and keeping track of right subtree
//f:if the sum is found then it is true else false
void checkSum(Node *root1,Node *root2,int sum,int &min,int &max,bool &f)
{
	if(root1==NULL || root2==NULL)
		return ;

	if(sum> max+min)
	{
		checkSum(root1->left,root2,sum,min,max,f);
		min=root1->data;

		if(max+min==sum)
		{
			f=true;
			return;
		}
		checkSum(root1->right,root2,sum,min,max,f);
	}

	else if(sum< max+min)
	{
		checkSum(root1,root2->right,sum,min,max,f);
		max=root2->data;

		if(max+min==sum)
		{
			f=true;
			return;
		}
		checkSum(root1,root2->left,sum,min,max,f);

	}
    else
        return;
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
			 5
           /   \
          3		8
         / \   /  \
        2   4  6   9
	   /
	  1

	*/

	Node *root=createNode(5);
	insert(&root,3);
	insert(&root,8);
	insert(&root,2);
	insert(&root,4);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    bool f=false;
    int min=(minVal(root))->data;
    int max=(maxVal(root))->data;
    checkSum(root,root,9,min,max,f);

    if(f)
    	cout<<"Sum Found !\n";
    else
    	cout<<"Sum not Found !\n";

	return 0;
}
