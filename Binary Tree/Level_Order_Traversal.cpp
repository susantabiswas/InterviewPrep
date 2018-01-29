//BFS or level order traversal of a tree
#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
};

Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->right = node->left = NULL;
		node->data = data;
		return node;
	}
	return NULL;
}

void levelOrderTraversal(Node* root){
	if(root == NULL)
		return;

	Node* curr = NULL;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		curr = q.front();
		q.pop();

		cout<<curr->data<<" ";
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
}


main(){
	/*			1
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

	levelOrderTraversal(root);

}
