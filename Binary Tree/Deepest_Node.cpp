//find the deepest node in a tree
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

//returns  the deepest node of tree using level order traversal
int findDeepestNode(Node *root){
	if(root==NULL)
		return 0;

	Node *el=NULL;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		el=q.front();
		q.pop();
		if(el->left)
			q.push(el->left);
		if(el->right)
			q.push(el->right);

	}
	return el->data;
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

	cout<<"Deepest Node:"<<findDeepestNode(root);
	return 0;
}
