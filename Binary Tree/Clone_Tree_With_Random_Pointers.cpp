//clone a binary tree having random pointers.
//Solution without hashing
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* random;
};

//creates node
Node* createNode(int data){
	Node* node = new Node;
	if(node){
		node->left = node->right = node->random = NULL;
		node->data = data;
		return node;
	}
	return NULL;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    /* First recur on left sutree */
    printInorder(node->left);

    /* then print data of Node and its random */
    cout << "[" << node->data << " ";
    if (node->random == NULL)
        cout << "NULL], ";
    else
        cout << node->random->data << "], ";

    /* now recur on right subtree */
    printInorder(node->right);
}

//inserts and creates clones .
//all the clones are inserted as the left child of the original node
//and their right child is also the clone of original node's right child
Node* createClones(Node* root){
	if(root == NULL)
		return NULL;

	//create a clone
	Node* clone_node = createNode(root->data);
	//link it with the root and its left child
	Node* left_child = root->left;
	clone_node->left = root->left;
	root->left = clone_node;

	//now recursively clone the remaining nodes
	if(left_child != NULL){
		left_child->left = createClones(left_child);
	}

	clone_node->right = createClones(root->right);
	return clone_node;
}


//sets the random pointer for the clones
void setRandom(Node* root, Node* clone){
	if(root == NULL)
		return;

	if(root->random ){
		clone->random = root->random->left;
	}
	else
		clone->random = NULL;

	//recurse for the remaining
	if(clone->left && root->left)
		setRandom(root->left->left,clone->left->left);
	setRandom(root->right,clone->right);
}


//for reverting back the original tree
void revertOriginal(Node* root, Node* clone){
	if(root == NULL)
		return;
	//if the left child is not NULL
	if(clone->left ){
		root->left = clone->left;
		clone->left = clone->left->left;
	}
	else
		root->left = NULL;

	revertOriginal(root->left,clone->left);
	revertOriginal(root->right,clone->right);
}

//clones a tree
Node* cloneTree(Node* root){
	//first create clones
	createClones(root);
	//set random pointers
	setRandom(root,root->left);
	//revert back changes to the original tree
	revertOriginal(root,root->left);
	return root;
}

main(){

	Node *tree = createNode(10);
    Node *n2 = createNode(6);
    Node *n3 = createNode(12);
    Node *n4 = createNode(5);
    Node *n5 = createNode(8);
    Node *n6 = createNode(11);
    Node *n7 = createNode(13);
    Node *n8 = createNode(7);
    Node *n9 = createNode(9);
    tree->left = n2;
    tree->right = n3;
    tree->random = n2;
    n2->left = n4;
    n2->right = n5;
    n2->random = n8;
    n3->left = n6;
    n3->right = n7;
    n3->random = n5;
    n4->random = n9;
    n5->left = n8;
    n5->right = n9;
    n5->random = tree;
    n6->random = n9;
    n9->random = n8;


    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);

    Node *clone = cloneTree(tree);

    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
}
