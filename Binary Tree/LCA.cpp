//find the lowest common ancestor i.e LCA assuming all the nodes are positive nos.
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

//finds the LCA in a binary tree
/*
	if the two nodes are on different sides then the first node to have it on different sides
	is the LCA or when they are on the same side then the first found is the LCA.
	each time we check if either of the 2 trees have found the LCA then return that node .

*/
Node* findLCA(Node* root,int a,int b){
	if(root==NULL)
		return NULL;
	if(root->data==a || root->data==b)
		return root;

	Node* left=findLCA(root->left,a,b);
	Node* right=findLCA(root->right,a,b);

	if(left && right)
		return root;
	else
		return left?left:right;

}

int main(){
/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);

	Node *t=findLCA(root,3,2);
	cout<<"LCS:"<<t->data;
	return 0;
}
