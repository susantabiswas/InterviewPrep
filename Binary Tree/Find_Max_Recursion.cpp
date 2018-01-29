//find the maximum element using recursion
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

//returns the maximum element
int findMax(Node *root){
	if(root==NULL)
		return 0;

	int max=INT_MIN;
	int left=findMax(root->left);
	int right=findMax(root->right);

	max=left>right?left:right;
	if(root->data>max)
		max=root->data;

	return max;
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

	cout<<findMax(root);
	return 0;
}
