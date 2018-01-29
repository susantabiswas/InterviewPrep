//make each node point to its immediate neighbour(sibling) using Iterative method

#include<iostream>
#include<queue>
using namespace std;

//node structure for tree node
struct Node{
	Node *left,*right,*nextSib;
	int data;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->nextSib=NULL;
		node->data=data;
		return node;
	}
	else
		return NULL;
}

//makes the nextSib point to its immediate neighbour
/*
	we use level order traversal for this
*/
void makeSibling(Node *root){
	if(root==NULL)
		return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	Node *el=NULL;
	while(!q.empty()){
		el=q.front();
		q.pop();

		if(el!=NULL){
			el->nextSib=q.front();	//make the curr element's nextSib point to the next node

		if(el->left)
			q.push(el->left);
		if(el->right)
			q.push(el->right);
		}
		else if(el==NULL){
			if(!q.empty())
				q.push(NULL);
		}

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

	makeSibling(root);
	cout<<root->left->left->nextSib->data;
	return 0;
}
