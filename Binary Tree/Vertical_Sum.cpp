//find the vertical sum in binary tree
/*
	for finding the vertical sum ,we require a colsum table so as to keep track of the
	columns
*/
#include<iostream>
#include<unordered_map>

using namespace std;

//for storing the column numbers and their sum
unordered_map<int,int> colsum;

//node structure for tree node
struct Node{
	Node *left,*right;
	int data;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->data=data;
		return node;
	}
	else
		return NULL;
}

//displays the vertical sum in a tree
void displayVerticalSum(Node *root,int col){
	if(root==NULL)
		return;

	if(colsum.find(col)==colsum.end()){
		colsum.insert(make_pair(col,root->data));		//when the column is not present
	}
	else{
		colsum[col]+=root->data;
	}
	displayVerticalSum(root->left,col-1);
	displayVerticalSum(root->right,col+1);
}

//driver function for the vertical sum function
void displayVerticalSumDriver(Node *root){
	displayVerticalSum(root,0);
	unordered_map<int,int>::iterator it;
	for(it=colsum.begin();it!=colsum.end();it++){
		cout<<it->first<<":"<<it->second<<endl;
	}
}

int main(){
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

	displayVerticalSumDriver(root);
	return 0;
}
