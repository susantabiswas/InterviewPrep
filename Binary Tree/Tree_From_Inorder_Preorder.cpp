//create a tree from given inorder and preorder list
#include<iostream>
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

//for finding the position of the node in the inorder list
int findPos(int *in,int start,int end,int key){
	for(int i=start;i<=end;i++){
		if(in[i]==key)
			return i;
	}
}

Node* buildTree(int pre[],int in[],int is,int ie){
	static int pre_in=-1;

	//create a node
	Node *node=createNode(pre[++pre_in]);

	//when inorder list has finished
	if(is>ie){
		return NULL;
	}
	if(is==ie)
		return node;

	//find the position of the root found from the preorder list in the inorder list
	int pos=findPos(in,is,ie,pre[pre_in]);

	node->left=buildTree(pre,in,is,pos-1);
	node->right=buildTree(pre,in,pos+1,ie);

	return node;
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
/*
				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	//preorder list
	int pre[]={1,2,3,4,5};
	//inorder list
	int in[]={3,2,4,1,5};

	Node *root=buildTree(pre,in,0,4);
	display(root);
	return 0;
}
