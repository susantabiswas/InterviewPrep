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


//finds the height of tree
int findHeight(Node *root){
	if(root==NULL)
		return 0;
	int l=findHeight(root->left);
	int r=findHeight(root->right);
	return max(l,r)+1;
}


//finds the diameter of the given tree
/*
	for each node check the height for the left and right subtrees and then
	check if the addition of those two is the greater than the current maximum
	NOTE:here the diameter is always 1 less ,i.e real diameter-1
*/
int findDiameter1(Node *root,int &len){
	if(root==NULL)
		return 0;

	int l=findDiameter1(root->left,len);
	int r=findDiameter1(root->right,len);

	if(l+r>len)
		len=l+r;
	return max(l,r)+1;
}

//another function for the same task with same complexity
int findDiameter2(Node *root){
	if(root==NULL)
		return 0;

	int lh=findHeight(root->left);
	int rh=findHeight(root->right);

	int ld=findDiameter2(root->left);
	int rd=findDiameter2(root->right);

	return max(lh+rh+1,max(ld,rd));
}

//driver function
void findDiameterDriver(Node *root){
	int len;

    int f1= findDiameter1(root,len)+1;
    int f2= findDiameter2(root);
    cout<<"diameter using f1:"<<f1<<" and f2:"<<f2;
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
