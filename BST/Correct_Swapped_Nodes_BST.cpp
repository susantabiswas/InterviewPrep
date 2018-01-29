//given a BST with two nodes swapped .Make corrections to make it a BST
/*
	using inorder traversal we see for abnormality in the nodes
	this problem is actually finding the swapped nodes in a sorted array
	so use 3 pointers :first,middle and last.
	all ini to NULL
	Now there can be 2 cases:
		1. when the swapped nodes are adjacent
		2. when they are not
	so we start traversing ,the first node which is smaller than its previous
	we store it in middle and its previous in first
	then continue if again we find one then store it in last
	then if last node is NOt NULL
		swap last and middle
	else
		swap first and middle
*/
#include<iostream>
#include<stack>
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

//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

}

//using iterative inorder traversal for finding the anomalies
void correctBST(Node* root){
	Node *first ,*last, *middle;
	first = last = middle = NULL;
	Node* prev = NULL;
	stack<Node*> s;

	if(root == NULL)
		return;

	while(1){
		while(root){
			s.push(root);
			root = root->left;
		}

		if(s.empty() || last!= NULL)
			break;
		root = s.top();
		s.pop();

		if(prev != NULL){
			if(prev->data > root->data){
				if(first == NULL){
					first = prev;
					middle = root;
				}
				else
					last = root;
			}
		}

		prev = root;
		root = root->right;
	}

	//when the swapped nodes are adjacent
	if(last == NULL){
		int t = first->data;
		first->data = middle->data;
		middle->data = t;
	}
	//when the swapped nodes are far apart
	else{
		int t = first->data;
		first->data = last->data;
		last->data = t;
	}
}

main(){
/*   	 6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    Node *root = createNode(6);
    root->left        = createNode(10);
    root->right       = createNode(2);
    root->left->left  = createNode(1);
    root->left->right = createNode(3);
    root->right->right = createNode(12);
    root->right->left = createNode(7);

    inOrderTraversal(root);
    correctBST(root);
    cout<<endl;
    inOrderTraversal(root);
}
