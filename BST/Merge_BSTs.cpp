//merge two given BSTs with TC:O(m+n)
//and space compl. :height of the first tree + height of the second tree
/*
	since the two trees can have different left and right subtrees structure
	,so what we do is we do inorder traversal:
	1. check if any of them is null or not
	2. if not then traverse as much as we can towards the left,untill both of them reaches end
	then since the entire height upto that of both the trees have been stored in the
	stack,
		2.1. check if either of the stack is empty or not
		2.2. we now pop the top element and compare them
			the smaller one is printed and its curr = curr->right
			towards the next inorder successor
			the larger one is pushed back and its curr = curr->left ,
			i.e towards the next inorder successor
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

	//tarverse towards the correct direction
	if(key > root->data)
		root->right = insertNodeBST(root->right, key);
	else if(key< root->data)
		root->left = insertNodeBST(root->left, key);
	return root;
}

//for traversal
//inorder traversal
void inOrderTraversal(Node* root){
	if(!root)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);

}

void mergeBST(Node* root1,Node* root2){
	Node* c1 = root1;
	Node* c2 = root2;
	stack<Node*> s1;
	stack<Node*> s2;


	//first check if any of them is empty or not
	if(root1 == NULL){
		inOrderTraversal(root2);
		return;
	}
	if(root2 == NULL){
		inOrderTraversal(root1);
		return;
	}

	//start traversal of trees
	while(c1 || !s1.empty() || c2 || !s2.empty()){
		//go left untill both of them ends
		while(c1 || c2){

			if(c1){
				s1.push(c1);
				c1 = c1->left;
			}
			if(c2){
				s2.push(c2);
				c2 = c2->left;
			}
		}

		//check the two stacks
		if(s1.empty()){
			while(!s2.empty()){
				cout<< (s2.top()->data)<<" ";
				s2.pop();
			}
			return;
		}

		if(s2.empty()){
			while(!s2.empty()){
				cout<<(s1.top()->data)<<" ";
				s1.pop();
			}
			return;
		}

		//when neither of them are non empty
		if(!s1.empty() && !s2.empty() && (s1.top()->data > s2.top()->data)){
			//cout<<"s2<s1 "<<"s2:"<<s2.top()->data<<" s1:"<<s1.top()->data<<" "<<"c1:"<<c1<<" c2:"<<c2<<" \n";
			cout<<s2.top()->data<<" ";

			c2 = s2.top();
			s2.pop();

			c2 = c2->right;
		}
		else if(!s1.empty() && !s2.empty() && (s1.top()->data < s2.top()->data)){
		//cout<<"s2>s1 "<<"s2:"<<s2.top()->data<<" s1:"<<s1.top()->data<<" "<<"c1:"<<c1<<" c2:"<<c2<<" \n";
			cout<<s1.top()->data<<" ";
			c1 = s1.top();
			s1.pop();

			c1 = c1->right;
		}
	}

}

main(){
	/* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    Node* root1 = createNode(3);
    root1->left = createNode(1);
    root1->right = createNode(5);

	inOrderTraversal(root1);
	cout<<endl;
	/* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    Node* root2 = createNode(4);
    root2->left = createNode(2);
    root2->right = createNode(6);
    inOrderTraversal(root2);
	 cout<<endl;
    mergeBST(root1, root2);

}
