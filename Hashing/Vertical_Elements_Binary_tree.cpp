//given a binary tree ,print its vertical elements
/*
	vertical distance is decided from the root node.Nodes under the same vertical
	line have the same distance from the root node.
	We subtract 1 from distance on moving left once and add 1 on moving right once
*/
#include<iostream>
#include<map>
#include<vector>
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

//for finding the vertical distance of the nodes and putting them into the hash table
//start with 0 and for each left turn subtract 1
//for each right turn add 1
void printVertical(Node* root, map<int,vector<int> > &h, int dist){
	if(root == NULL)
		return;
	printVertical(root->left, h, dist-1);
	h[dist].push_back(root->data);
	printVertical(root->right, h, dist+1);
}

//driver function
void printVerticalDriver(Node* root){
	map< int,vector<int> >h;
	int dist = 0;
	printVertical(root, h, dist);

	//print the hash table values
	map<int,vector<int> >:: iterator it;
	for(it = h.begin(); it!=h.end(); it++){
		for(int i = 0; i< it->second.size(); i++)
			cout<<it->second[i]<<" ";
		cout<<endl;
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

    printVerticalDriver(root);
}
