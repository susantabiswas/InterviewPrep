//find the path in a a binary tree with given sum

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

//find whether there exists a path where the given sum exists
bool sumExists(Node *root,int sum){
	if(root==NULL)
		return false;
	sum=sum-root->data;
	if(sum==0)
		return true;
	if(sum<0)
		return false;

	return sumExists(root->left,sum)||sumExists(root->right,sum);
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

	cout<<sumExists(root,6);
	return 0;
}
