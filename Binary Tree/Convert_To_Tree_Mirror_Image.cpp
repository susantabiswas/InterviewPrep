//convert a tree to its mirror image

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

//converts a tree to its mirror image
Node* convertToMirrorImage(Node* root){
	if(root==NULL)
		return NULL;

	Node *l=convertToMirrorImage(root->left);
	Node *r=convertToMirrorImage(root->right);

	//now change the right and left child links
	root->left=r;
	root->right=l;
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

	display(root);
	cout<<endl;
	convertToMirrorImage(root);
	display(root);
	return 0;
}
