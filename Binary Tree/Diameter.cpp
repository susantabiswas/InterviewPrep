//Find the diameter of a tree
/*
	approach 1: TC: O(n^2):
		We find the left height and right height also for the possibility that
		there might exist a subtree greater than the current left or right
	approach 2: TC:O(n):
		We find the height in the same recursive call only.
*/
#include<iostream>
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

//preorder traversal
void preOrderTraversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

//for finding the height of a tree
int findHeight(Node* root){
	if(!root)
		return 0;
	return max( findHeight(root->left), findHeight(root->right)) + 1;
}

//finds the diameter using separate height calls
int findDiameter1(Node* root){
	if(root == NULL)
		return 0;

	//find the left and right heights
	int lh = findHeight(root->left);
	int rh = findHeight(root->right);

	//find the left and right diameters
	int ld = findDiameter1(root->left);
	int rd = findDiameter1(root->right);

	//now decide whether the current subtree or the greatest subtree on left
	//or on right should be selected
	return max( lh + rh + 1, max(ld, rd) );
}

//finds the diameter
/*
	We update the height in each recursive call itself using pointers to them
*/
int findDiameter2(Node* root, int* h){
	if(!root )
		return 0;
	int lh = 0;
	int rh = 0;

	int ld = findDiameter2(root->left, &lh);
	int rd = findDiameter2(root->right, &rh);

	*h = max(lh ,rh) + 1;
	return max( lh +rh + 1, max(ld,rd));
}

//finds the diameter using 2nd approach
int findDiameter2Driver(Node* root){
	int h = 0;
	int d = findDiameter2(root, &h);
	return d;
}

main(){
 /*         1
          /   \
        2      3
      /  \
    4     5
  */
  Node *root 		= createNode(1);
  root->left        = createNode(2);
  root->right       = createNode(3);
  root->left->left  = createNode(4);
  root->left->right = createNode(5);

	preOrderTraversal(root);
	cout<<endl;
	cout<< findDiameter1(root);
	cout<<endl;
	cout<< findDiameter2Driver(root);
}
