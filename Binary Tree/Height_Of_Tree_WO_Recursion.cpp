//find height of the tree without recursion
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

//finds the height of  the tree using level order traversal
/*
	we need to keep track of the level during the traversal
*/
int findHeightOfTree(Node *root){
	if(root==NULL)
		return 0;

	Node *el=NULL;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);		//this helps us to mark the end of a level

	int height=0;

	while(!q.empty()){
		el=q.front();
		q.pop();

		if(el==NULL){
			height++;
			if(q.empty())  //when all the nodes are finished last is null so we end it there
				break;
			q.push(NULL);
		}
		else{
				if(el->left){
					q.push(el->left);
				}
			    if(el->right){
					q.push(el->right);
				}
	    }

	}
	return height;
}

int main(){
/*				1
			  /  \
			 2    5
			/ \
		  3   4
*/
	Node *root=createNode(1);
	root->right=createNode(5);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(4);

	cout<<"Height:"<<findHeightOfTree(root);
	return 0;
}
