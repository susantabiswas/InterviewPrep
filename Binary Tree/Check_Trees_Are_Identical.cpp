//check if two trees are identical or not

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

//checks if two trees are identical or not
bool isIdentical(Node *root1,Node *root2){
	if(!root1 && !root2)
		return true;
	if(!root1 || !root2)
		return false;
	if(root1 && root2 && root1->data!=root2->data)
		return false;

	return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
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

/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	Node *root2=createNode(1);
	root2->right=createNode(5);
	root2->left=createNode(2);
	root2->left->left=createNode(3);
	root2->left->right=createNode(4);

	cout<<isIdentical(root1,root2);
	return 0;
}
