//find the LCA of a and b in BST where  a<b

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

//finds LCA in BST
/* first node lying between a and b is the LCA
*/
int LCA(Node *root,int a,int b){
	if(root==NULL)	//when there is no LCA available
		return 0;
	if(root->data >a && root->data<b)
		return root->data;
	 if(root->data<a && root->data<b)
		return LCA(root->right,a,b);
	 else if(root->data>a && root->data>b)
		return LCA(root->left,a,b);
	 else if(root->data==a || root->data==b)
		return root->data;
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
/*				 3
			  /   \
			 -2     5
			/ \
		  -3   1
		  /
		  -4
*/
	Node *root=createNode(3);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	root->left->left->left=createNode(-4);
	root->left->right=createNode(1);

	cout<<"LCA:"<<LCA(root,-4,-3);
	return 0;
}
