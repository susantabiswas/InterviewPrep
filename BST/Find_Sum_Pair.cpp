//Given a key ,check whether there exists any pair whose sum is equal to the key
/*
	Start traversal both from leftmost of inorder traversal and rightmost of it
	After each node check whether the sum of nodes is equal to the key or not
	do just like the array ques. if not equal
*/
#include<iostream>
#include<stack>
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

	//traverse towards the correct direction
	if(key > root->data)
		root->right = insertNodeBST(root->right, key);
	else if(key< root->data)
		root->left = insertNodeBST(root->left, key);
	return root;
}

//for finding whether there is any pair whose sum is equal to the key
/*
	start iterative inorder traversal from front and one from behind i.e reverse
	inorder traversal
*/
bool isSumPairPresent(Node* root, int key){
	stack<Node*> s1;	//for inorder
	stack<Node*> s2;	//for reverse inorder
	Node* c1 = root;
	Node* c2 = root;
	int v1 ,v2 ;
	bool normalTrav = true;
	bool reverseTrav = true;

	while(1){

		if(normalTrav){
			//start traversal for normal inorder
			while(c1){
				//go as left as possible
				s1.push(c1);
				c1 = c1->left;
			}

			//take the left most node
			c1 = s1.top();
			s1.pop();
			normalTrav = false;
		}

		if(reverseTrav){

			//start traversal for reverse inorder
			while(c2){
				//go as right as possible
				s2.push(c2);
				c2 = c2->right;
			}

			//take the left most node
			c2 = s2.top();
			s2.pop();
			reverseTrav = false;
		}

		//cout<<c1->data<<" "<<c2->data<<endl;
		//now check
		//when the sum is found
		if( c1->data != c2->data && c1->data + c2->data == key)
			return true;
		//when the lesser than the key ,then increase c1 by moving to the
		//successor
		else if(c1->data + c2->data < key){
			c1 = c1->right;
			normalTrav = true;
		}
		//when the greater than the key ,then decrease c2 by moving to the
		//successor
		else if(c1->data + c2->data > key){
			c2 = c2->left;
			reverseTrav = true;
		}

		//when either of the traversal has finished
		if(s1.empty() || s2.empty())
			return false;
	}
	return false;
}
//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

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

	cout<<isSumPairPresent(root,81);

}
