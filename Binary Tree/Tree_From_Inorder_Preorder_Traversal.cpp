//build a tree using the given inorder and preorder traversal

#include<iostream>
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

Node* buildTree(vector<int> pre,vector<int> in){
	int root_data = pre[0];
	int root_index = -1;

	if(pre.size() == 1){
		Node* node = createNode(root_data);
		return node;
	}

	//search this in the inorder list
	vector<int>::iterator it;
	for(it = begin(in); it!=end(in); it++){
		if(*it == root_data){
			root_index = it - in.begin();
			break;
		}
	}

	//create a node
	Node* node = createNode(root_data);
	node->left = buildTree( vector<int>(pre.begin()+1,pre.begin() + root_index +1),
							vector<int>(in.begin(),it)
						  );

	node->right = buildTree( vector<int>(pre.begin() + root_index + 1,pre.end() ),
							 vector<int>(++it,in.end())
							 );
	return node;
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
/*				1
			  /   \
			 2     5
			/ \
		  3   4
*/
	vector<int> pre = {1,2,3,4,5};
	vector<int> in = {3,2,4,1,5};
	Node* root = buildTree(pre,in);
	inOrderTraversal(root);
}
