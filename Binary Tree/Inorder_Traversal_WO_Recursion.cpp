//inorder traversal without recursion
#include<iostream>
#include<stack>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
};

//creates node
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->left = node->right = NULL;
		node->data = data;
		return node;
	}
	return NULL;
}

void inOrderTraversalStack(Node* root){
	if(root == NULL)
		return;

	stack<Node*> s;
	
	while(1){
		//go as far left as possible
		while(root){
			s.push(root);
			root = root->left;
		}

		//check if the stack has become empty,there are no more nodes left after 
		//traversing left subtree of last node
		if(s.empty())
			break;

		//pop the last leaf node and go to its right subtree
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		root = root->right;
	}
}

main(){
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

	inOrderTraversalStack(root);
	cout<<endl;
}