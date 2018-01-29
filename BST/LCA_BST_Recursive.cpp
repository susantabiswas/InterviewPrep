//find the LCA for two nodes a and b in BST
//LCA for nodes lying on diff side of a node is the first node on whose diff sides
//the two nodes lie or when.
//if the two nodes lie on the same side then the first node to appear is the ancestor
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

//post order traversal
void postOrderTraversal(Node* root){
	if(!root)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";

}

//finds the lca in bst
Node* findLCA(Node* root, int a, int b){
	if(root == NULL)
		return NULL;
	//if the two nodes lie on diff sides
	if(root->data > a && root->data<b)
		return root;
	//if both lie on left side
	else if(root->data >a && root->data>b)
		return findLCA(root->left,a,b);
	else if(root->data<a && root->data<b)
		return findLCA(root->right,a,b);
	else if(root->data == a || root->data == b)
		return root;
}

main(){
/*				 3
			  /   \
			 -2     5
			/ \
		  -3   1
		  /
		  -4
*/
	Node *root=createNode(3);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	root->left->left->left=createNode(-4);
	root->left->right=createNode(1);

	Node* lca = findLCA(root,-3,1);
	cout<<lca->data;
	cout<<endl;
}
