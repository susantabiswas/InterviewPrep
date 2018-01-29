//Level order traversal
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

//displays the tree using level order traversal
void levelOrderTraversal(Node *root){
	if(root==NULL)
		return;

	Node *el=NULL;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		el=q.front();
		q.pop();
		cout<<el->data<<" ";

		if(el->left)
			q.push(el->left);
		if(el->right)
			q.push(el->right);

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

	levelOrderTraversal(root);
	return 0;
}
