//postorder traversal without recursion
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

/*
	In post order we visit each node twice and on the second time we visit
	we print the node .
	Now printing can occur at 3 conditions:
	1) when it is a leaf node
	2) when the node doesn't have a right child
	3) when a node is visited twice on moving up the right subtree

*/
void postOrderTraversal(Node* root){
	//check if the NULL tree or not
	if(!root)
		return;

	Node* curr = NULL;
	Node* prev = NULL;
	stack<Node*> s;

	s.push(root);
	while(!s.empty()){
		curr = s.top();

		//check if it is a leaf node
		if(!curr->left && !curr->right){
			cout<<curr->data<<" ";
			s.pop();
		}
		//if we are going down the subtree
		else if(!prev || prev->left == curr
				|| prev->right == curr){
			if(curr->left)
				s.push(curr->left);
			else if(curr->right)
				s.push(curr->right);
		}
		//if we are moving up in left subtree without right child
		else if(prev == curr->left){
			if(!curr->right){
				cout<<curr->data<<" ";
				s.pop();
			}
			else{
				s.push(curr->right);
			}
		}
		//when moving up the right subtree
		else if(prev == curr->right){
			//print the node
			cout<<curr->data<<" ";
			s.pop();
		}

		//set value to prev node
		prev = curr;
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

	postOrderTraversal(root);
	return 0;
}
