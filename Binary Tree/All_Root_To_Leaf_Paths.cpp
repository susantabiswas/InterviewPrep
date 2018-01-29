//print all the root to leaf paths
#include<iostream>
#include<vector>
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

//prints the vector
void printArray(vector<int> arr,int len){
	for (int i = 0; i <len; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

//prints all the root to leaf paths
void printPath(Node *root,vector<int> &path,int len){
	if(root==NULL)
		return;
	//add given node to the path list
	path[len++]=root->data;

	if(root->left==NULL && root->right==NULL){	//leaf node found
		printArray(path,len);
		return;
	}
	printPath(root->left,path,len);
	printPath(root->right,path,len);
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

	vector<int> path(100);
	int len=0;
	printPath(root,path,len);
	return 0;
}
