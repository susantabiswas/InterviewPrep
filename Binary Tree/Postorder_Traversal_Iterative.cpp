//Postoder traversal using iterative method

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
/*
	we keep track of the previous node of the current node,there can be three conditions:
	1.going down the left subtree or right subtree where the previous is always the parent
	 of the current node
	2.going up the right subtree where the previous is the right child of the current node,and
	  this is when we display the current node because in postorder traversal we visit each node twice
	  and when we are visiting for the second time on coming from the right child ,we print it.
	3.going up the tree when the previous is the left child of the current node

	Note:When the node is a leaf node it is printed or when it doesn't have a right child
*/
void postorder_Iterative(Node *root){
	if(root==NULL)
		return;

	Node *prev=NULL;
	Node *curr=NULL;

	stack<Node*> s;
	s.push(root);

	while(!s.empty()){
		curr=s.top();

		if(!curr->left && !curr->right){
			cout<<curr->data<<" ";
			s.pop();
		}
		else if(!prev || prev->left==curr || prev->right==curr){		//when going down the tree
			if(curr->left)
				s.push(curr->left);
			else if(curr->right)
				s.push(curr->right);
		}
		else if(prev==curr->left){			//when going up from the left subtree
			if(!curr->right){				//when there is no right child print else go right
				cout<<curr->data<<" ";
				s.pop();
			}
			else if(curr->right){
				s.push(curr->right);
			}
		}
		else if(prev==curr->right){			//when the prev is the right child,then print
			cout<<curr->data<<" ";
			s.pop();
		}

		prev=curr;
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

	postorder_Iterative(root);
	return 0;
}
