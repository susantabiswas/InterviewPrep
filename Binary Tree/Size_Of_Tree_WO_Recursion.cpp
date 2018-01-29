//finds the size of the binary tree using Level order traversal
#include<iostream>
#include<queue>
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

//finds the size of the tree using level order traversal
int findSizeOfTree(Node *root){
	if(root==NULL)
		return 0;
	int c=0;
	Node *el=NULL;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		el=q.front();
		++c;
		q.pop();

		if(el->left)
			q.push(el->left);
		if(el->right)
			q.push(el->right);

	}
	return c;
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

	cout<<"Size:"<<findSizeOfTree(root);
	return 0;
}
