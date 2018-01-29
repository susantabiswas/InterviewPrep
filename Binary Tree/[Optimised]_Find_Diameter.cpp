//find the diameter of the binary tree
//TC:O(n^2)
#include<iostream>
using namespace std;

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


//finds the diameter of the given tree
/*
	for each node check the height for the left and right subtrees.To improve complexity
	from the previous solution here height is calculated in the recursive call itself
*/
int findDiameter(Node *root,int *h){
	int lh=0,rh=0;

	if(root==NULL){
		*h=0;
		return 0;
	}

	int ld=findDiameter(root->left,&lh);
	int rd=findDiameter(root->right,&rh);

	*h=max(ld,rd)+1;
	return max(lh+rh+1,max(ld,rd));
}

//driver function
void findDiameterDriver(Node *root){
	 int h=0;

    int f= findDiameter(root,&h);
    //int f2= findDiameter2(root);
    cout<<"diameter :"<<f;
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

	findDiameterDriver(root);
	return 0;
}
