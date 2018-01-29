//search an element using iterative method
#include<iostream>
#include<queue>
#include<climits>
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

//finds element using level order traversal
bool searchElement(Node *root,int key){
	if(root==NULL)
		return false;

	Node *el=NULL;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		el=q.front();

		if(el->data==key)
			return true;
		q.pop();

		if(el->left)
			q.push(el->left);
		if(el->right)
			q.push(el->right);

	}
	return false;
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

	cout<<searchElement(root,6);
	return 0;
}
