//check if the two binary trees are mirror image of each other

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

//checks if two trees are mirror image of each other or not
bool isMirror(Node *root1,Node *root2){
	if(!root1 && !root2)
		return true;
	if(!root1 || !root2)
		return false;
	if(root2->data!=root1->data)
		return false;

	return isMirror(root1->left,root2->right)&& isMirror(root1->right,root2->left);
}

int main(){
/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	Node *root1=createNode(1);
	root1->right=createNode(5);
	root1->left=createNode(2);
	root1->left->left=createNode(3);
	root1->left->right=createNode(4);

	/*			1
			  /   \
			 5     2
			      / \
		  		   4  3
*/
	Node *root2=createNode(1);
	root2->left=createNode(5);
	root2->right=createNode(2);
	root2->right->right=createNode(3);
	root2->right->left=createNode(44);

	cout<<isMirror(root1,root2);
	return 0;
}
