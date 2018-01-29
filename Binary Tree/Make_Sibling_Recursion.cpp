//make each node point to its immediate neighbour(sibling)

#include<iostream>
using namespace std;

//node structure for tree node
struct Node{
	Node *left,*right,*nextSib;
	int data;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->nextSib=NULL;
		node->data=data;
		return node;
	}
	else
		return NULL;
}

//makes the nextSib point to its immediate neighbour
void makeSibling(Node *root){
	if(root==NULL)
		return;

	//make the left child's nextSib point to the right child if both exists
	if(root->left && root->right)
		root->left->nextSib=root->right;

	//now make the right child's nextSib point to the next sibling
	if(root->right && root->nextSib)
		root->right->nextSib=root->nextSib->left;

	makeSibling(root->left);
	makeSibling(root->right);

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

	makeSibling(root);
	//cout<<root->right->nextSib;
	return 0;
}
