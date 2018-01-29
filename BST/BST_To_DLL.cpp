//convert a BST to DLL
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

//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

}

Node* convertToDLL(Node* root, Node* &prev){
	if(root == NULL)
		return NULL;

	convertToDLL(root->left, prev);

	root->left = prev;
	if(prev)
		prev->right = root;
	prev = root;
	Node* nextptr = root->right;
	root->right = NULL;
	
	convertToDLL(nextptr, prev);
	return root;
}

Node* convertToDLLDriver(Node* root){
	Node* prev = NULL;
	Node* head = convertToDLL(root, prev);

	//find the starting point of the DLL
	while(head->left)
		head = head->left;
	return head;
}

void disp(Node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}
main(){
	/*
			  4
			/    \
		  2      6
		/  \    / \
		1   3   5  7
	*/
	Node* root = NULL;
	root = insertNodeBST(root,4);
	root = insertNodeBST(root,2);
	root = insertNodeBST(root,1);
	root = insertNodeBST(root,3);
	root = insertNodeBST(root,6);
	root = insertNodeBST(root,5);
	root = insertNodeBST(root,7);

	inOrderTraversal(root);
	cout<<endl;

	Node* head = convertToDLLDriver(root);
	disp(head);
}
