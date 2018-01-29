//delete a node in BST

#include<iostream>
#include<climits>
using namespace std;

//node structure for tree node
struct Node{
	Node *left,*right;
	int data;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->data=data;
		return node;
	}
	else
		return NULL;
}

//finds the maximum node
Node* findMax(Node *root){
	if(root==NULL)
		return NULL;
	if(root->right==NULL)
		return root;
}

//deletes a node in BST
/*
	-if the node to be deleted is not found then return else
	-if the node is a leaf node then delete that node
	-else if the node has only one child then make that child point to the
	 child pointer of its parent
    -if the node has both the children
	 then find the maximum child in its left subtree and replace with it and delete that node
*/
Node *deleteNode(Node*root,int key){
	if(root==NULL){					//if the key is not present
		cout<<"Key not found !";
		return NULL;
	}

	if(root->data==key){
		if(!root->left && !root->right){	//if the node is a leaf node
			delete root;
			return NULL;
		}
		else if (!root->left || !root->right)//if either the left or right child is present
		{
			Node *t=NULL;
			if(root->left){
				t=root->left;
			}
			else if(root->right){
				t=root->right;
			}
			delete root;
			return t;
		}
		else if(root->left && root->right){
			//when it has both
			//find max in left subtree

			Node *t=root->left,*prev=NULL;
			while(t->right){
				prev=t;
				t=t->right;
			}
			if(prev==NULL)
				root->left=NULL;
			else
				prev->right=NULL;
			root->data=t->data;
			delete t;
		}
	}

	if(root->data>key){
		root->left=deleteNode(root->left,key);
	}
	else if(root->data<key){
		root->right=deleteNode(root->right,key);
	}
	return root;
}

//displays the tree using inorder traversal
void display(Node *root){
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" " ;
	display(root->right);
}

int main(){
/*				 1
			  /   \
			 -2     5
			/ \
		  -3    0
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	//root->left->right=createNode(0);

	cout<<"Initially:";
	display(root);
	deleteNode(root,-2);
	cout<<"\nAfter deletion:";
	display(root);
	return 0;
}
