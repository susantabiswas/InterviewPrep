//check if the given tree is AVL tree or not

#include<iostream>
#include<cmath>
using namespace std;

//node structure for AVL tree node
struct Node{
	Node *left,*right;
	int data;
	int height;
};

//creates node for tree
Node* createNode(int data){
	Node *node=new Node;
	if(node){
		node->left=NULL;
		node->right=NULL;
		node->data=data;
		node->height=0;
		return node;
	}
	else
		return NULL;
}

//returns the height of the node
int getHeight(Node* root){
	if(root==NULL)
		return 0;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

//Single rotation Left
/*
	here imbalance is due to difference in height in the left subtree ,and we make
	it the right child of its left subtree and its left subtree now takes its place

		Q				        W
	   / \					   / \
	  W	  1===============>   2  Q
	 / \ 						/ \
	2   3 			           3   1
*/
Node* singleRotationLeft(Node* root){
	Node *W=root->left;
	root->left=W->right;
	W->right=root;
	return W;
}



//Single rotation right
/*
	here imbalance is due to difference in height in the right subtree ,and we make
	it the left child of its right subtree and its right subtree now takes its place

				Q				        	  W
			   / \					   		 / \
			  1   W	  ===============>       Q  3
				 / \ 						/ \
				2   3 			           1   2
*/
Node* singleRotationRight(Node* root){
	Node *W=root->right;
	root->right=W->left;
	W->left=root;
	return W;
}

//double rotation for fixing RL imbalance
/*
	refer diagram from book :P
*/
Node* doubleRotationRightLeft(Node *root){
	//first do single left rotation in the left subtree of right child
	root->right=singleRotationLeft(root->right);
	//single right rotation
	return singleRotationRight(root);
}


//double rotation for fixing LR imbalance
/*
	refer diagram from book :P
*/
Node* doubleRotationLeftRight(Node *root){
	//first do single right rotation in the right subtree of left child
	root->left=singleRotationRight(root->left);
	//single left rotation
	return singleRotationLeft(root);
}

//inserts a node into the AVL tree
/*
	Insert an node when we reach NULL position and after that chech whether the tree has become
	unbalanced or not
*/
Node* insertAVLNode(Node* root,int key){
	//create a node and insert
	if(root==NULL){
		Node *node=createNode(key);
		return node;
	}
	//right subtree
	if(key>root->data){
		//go to the right subtree
		root->right=insertAVLNode(root->right,key);

		//check for imbalance
	if(getHeight(root->right) - getHeight(root->left)==2){
			//fix the imbalance using rotation
			//check whether it is left ,right ,LR or RL rotation

			//single right rotation
			if(key>root->right->data){
				root=singleRotationRight(root);
			}
			//right left double rotation
			else{
				root=doubleRotationRightLeft(root);
			}
		}

	}
	//left subtree
	else if(key<root->data){
		root->left=insertAVLNode(root->left,key);

		//check for imbalance
		if(getHeight(root->left) - getHeight(root->right)==2){
			//fix the imbalance using rotation
			//check whether it is left ,right ,LR or RL rotation

			//left single rotation
			if(key<root->left->data){
				root=singleRotationLeft(root);
			}
			//left right double rotation
			else{
				root=doubleRotationLeftRight(root);
			}
		}

	}

	//update the height

		root->height=max(getHeight(root->left),getHeight(root->right))+1;
	return root;
}

//checks whether the given tree is AVL or not
bool checkIsAVL(Node* root){
	if(root==NULL)
		return true;
	if(root->left && root->right && abs(root->left->height - root->right->height)>1)
		return false;
	else if(root->left && root->left->height>1)
		return false;
	else if(root->right && root->right->height>1)
		return false;
	else
		return true;
	return checkIsAVL(root->left) && checkIsAVL(root->right);
}

int main(){
	//tree 1 which is AVL
/*			    4
			  /   \
			 2     5
			/ \
		  1   3
*/
	Node *root1=createNode(4);
	insertAVLNode(root1,2);
	insertAVLNode(root1,5);
	insertAVLNode(root1,1);
	insertAVLNode(root1,3);

	//tree2 which is not AVL
	/*			4
			  /   \
			 2     5
			/ \
		   1   3
		  /
		 0

	*/
	Node *root2=createNode(4);
	root2->height=4;
	root2->right=createNode(5);
	root2->right->height=1;
	root2->left=createNode(2);
	root2->left->height=3;
	root2->left->left=createNode(1);
	root2->left->left->height=2;
	root2->left->left->left=createNode(0);
	root2->left->left->left->height=1;
	root2->left->right=createNode(3);
	root2->left->right->height=1;

	cout<<"tree1:"<<checkIsAVL(root1);
	cout<<"\ntree2:"<<checkIsAVL(root2);
	return 0;
}
