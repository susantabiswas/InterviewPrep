//find the maximum width of a tree i.e, the maximum num of nodes at any level
#include<iostream>
#include<queue>
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

//finds the maximum width of a tree
int getMaxWidth(Node* root){
	if(root == NULL)
		return NULL;

	int c = 0;
	int maxCount = 0;
	Node *curr = NULL;
	queue<Node*> q;
	Node* dummy = NULL;
	q.push(root);
	q.push(dummy);

	while(!q.empty()){
		curr = q.front();
		q.pop();

		if(curr == NULL){
			if(c >maxCount)
				maxCount = c;
			c = 0;
			if(q.empty())
				break;
			q.push(dummy);
		}
		else{
			if(curr->left){
				q.push(curr->left);
				++c;
			}

			if(curr->right){
				q.push(curr->right);
				++c;
			}
		}
	}
	return maxCount;
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

	cout<<getMaxWidth(root);
}
