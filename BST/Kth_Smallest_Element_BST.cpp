///find the kth smallest element in a bst
#include<iostream>
#include<limits>
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

//Inserts a node in the BST
Node* insertNodeBST(Node* root, int key){
	//if we have reached the leaf position
	if(root == NULL)
		return createNode(key);

	//tarverse towards the correct direction
	if(key > root->data)
		root->right = insertNodeBST(root->right, key);
	else if(key< root->data)
		root->left = insertNodeBST(root->left, key);
	return root;
}

//for traversal

//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

}

//finds the kth smallest element
int findKthSmallest(Node* root, int &k){
	if(root == NULL)
		return numeric_limits<int>::max();

	int l = findKthSmallest(root->left, k);

	if(l != numeric_limits<int>::max())
		return l;
	--k;
	
	if(k == 0)
		return root->data;

	int r = findKthSmallest(root->right, k);
	if(r != numeric_limits<int>::max())
		return r;
	return numeric_limits<int>::max();
}

main(){
	/*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insertNodeBST(root, 50);
    root = insertNodeBST(root, 30);
    root = insertNodeBST(root, 20);
    root = insertNodeBST(root, 40);
    root = insertNodeBST(root, 70);
    root = insertNodeBST(root, 60);
    root = insertNodeBST(root, 80);

	int k = 5;
	int temp = k;
	inOrderTraversal(root);
	cout<<endl<<findKthSmallest(root,temp);

}
