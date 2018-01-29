//Iterative solution for preorder traversal
#include<iostream>
#include<stack>
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

//displays the tree in preorder traversal using Iterative method
void preorder_Iterative(Node *root){
	if(root==NULL)
		return;

	stack<Node*> s;
	//start traversal
	while(1){

		//go as far as in the left subtree
		while(root!=NULL){
			s.push(root);
			//since it is preorder traversal print the nodes as they are pushed
			cout<<root->data<<" ";
			root=root->left;
		}

		//check if the traversal is complete or not
		if(s.empty())
			break;

		//go to the right subtree if it exists
		root=s.top();
		s.pop();
		root=root->right;
	}
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

	preorder_Iterative(root);
	return 0;
}
