//search element in a tree

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

//searches the element in the tree
bool searchKey(Node *root,int key){
	if(root==NULL)
		return false;
	if(key==root->data)
		return true;
	return searchKey(root->left,key)||searchKey(root->right,key);
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

	cout<<"key:5 found:"<<searchKey(root,5);
	return 0;
}
