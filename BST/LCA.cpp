//find the LCA for two nodes a and b
//LCA for nodes lying on diff side of a node is the first node on whose diff sides
//the two nodes lie.
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

Node* findLCA(Node* root, int a, int b){
	if(root == NULL)
		return NULL;

	Node* l = findLCA(root->left,a,b);
	Node* r = findLCA(root->right,a,b);

	if(root->data == a || root->data == b)
		return root;

	if(l && r)
		return root;
	else if(l || r)
		return l?l:r;
	else
		return NULL;
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

	Node* lca = findLCA(root,3,5);
	cout<<lca->data;
	cout<<endl;
}
