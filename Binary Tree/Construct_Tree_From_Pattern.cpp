//make a tree from the given string pattern where L=Leaf node and I=Internal node

#include<iostream>
using namespace std;

//node structure for tree node
struct Node{
	Node *left,*right;
	char data;
};

//creates node for tree
Node* createNode(char data){
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

//creates a given tree from a string pattern
Node* makeTree(string str){
	static int in=-1;
	if(str[in]=='\0')
		return NULL;

	//make a node
	Node *node=createNode(str[++in]);
	if(str[in]=='L')		//when a leaf node is there
		return node;
	else {
		node->left=makeTree(str);
		node->right=makeTree(str);
		return node;
	}

}

//displays the tree using inorder traversal
void display(Node *root){
	if(root==NULL)
		return;
	display(root->left);
	cout<<root->data<<" " ;
	display(root->right);
}

int main(){
/*				 I
			  /   \
			 L     I
					/ \
				  L   L
*/

	string str="ILILL";
	Node *root=makeTree(str);
	display(root);
	return 0;
}
