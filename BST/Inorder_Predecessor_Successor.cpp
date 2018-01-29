//given a node ,find its inorder successor and predecessor in the BST.
//if the node doenst exits then find the nodes between which it should have existed
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
};

struct PredSucc{
	Node* pred;
	Node* succ;

	PredSucc(){
		pred = succ = NULL;
	}
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
//preorder traversal
void preOrderTraversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

//finds the inorder successor
Node* findSuccessor(Node* root){
	if(root == NULL)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

//finds the inorder predecessor
Node* findPredecessor(Node* root){
	if(root == NULL)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}

//finds the inorder predecessor and successor of a node
/*
	if the node is found:
		pred = rightmostnode(left child)
		succ = leftmostnode(right child)
	else:
		if key > root->data move towards the right subtree
			pred = root
		if key < root->data ,we move left
			succ = root
*/
void findPredecessorSuccessor(Node* root, PredSucc* node, int key){
	if(root == NULL)
		return;

	//when key is found
	if(root->data == key){
		node->pred = findPredecessor(root->left);
		node->succ = findSuccessor(root->right);
		return;
	}
	else if(key > root->data){
		node->pred = root;
		findPredecessorSuccessor(root->right,node,key);
	}
	else{
		node->succ = root;
		findPredecessorSuccessor(root->left,node,key);
	}
}

//driver function
PredSucc* findPredecessorSuccessorDriver(Node* root,int key){
	PredSucc *node = new PredSucc();
	findPredecessorSuccessor(root,node,key);
	return node;
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

	//preOrderTraversal(root);
	PredSucc *node = new PredSucc();
	node = findPredecessorSuccessorDriver(root,65);
	cout<<node->pred->data<<" "<<node->succ->data<<endl;
}
