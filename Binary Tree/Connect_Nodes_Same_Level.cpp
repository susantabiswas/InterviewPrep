//connect nodes lying at the same level using BFS
#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* rightMost;
};

//creates node
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->left = node->rightMost = node->right = NULL;
		node->data = data;
		return node;
	}
	return NULL;
}

void connectNodes(Node* root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	Node* curr = NULL;

	//Make the current node's rightmost point to the next front Node of queue,
	//last node of queue will point to NULL
	while(!q.empty()){
		curr = q.front();
		q.pop();

		if(curr == NULL){
			if(q.empty())
				break;
			q.push(NULL);
		}
		else{
			curr->rightMost = q.front();
			//cout<<curr->data<<" "<<curr->rightMost<<endl;
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
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
	//cout<<root->left->data<<" ";
	connectNodes(root);
	cout<<root->left->left->data<<" "<<root->left->left->rightMost->data<<" \n";
	//cout<<root->left->rightMost->rightMost;

}
