//find the shortest nodes in a BST
/*
	Shortest path is the path along the ancestor of the two nodes
	Find the ancestor and then from there find path for each of a and b
*/
#include<iostream>
#include<climits>
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

//finds LCA in BST
/* first node lying between a and b is the LCA
*/
Node* LCA(Node *root,int a,int b){
	if(root==NULL)	//when there is no LCA available
		return NULL;
	if(root->data >a && root->data<b)
		return root;
	 if(root->data<a && root->data<b)
		return LCA(root->right,a,b);
	 else if(root->data>a && root->data>b)
		return LCA(root->left,a,b);
	 else if(root->data==a || root->data==b)
		return root;
}

//finds the shortest path between a and b
/*
	first find the ancestor ,then find the path
	from there
*/
void findShortestPath(Node *root,int a ,int b){
	Node *anc=LCA(root,a,b);
	vector<int> path;
	Node *t;
	//check whether  a and b lie on the same sub tree
	if(anc->data==a || anc->data==b){
		t=anc;
		int second;
		if(anc->data==a)
			second=b;
		else
			second=a;

		while(t){
			path.push_back(t->data);
			if(t->data>second)
				t=t->left;
			else if(t->data<second)
				t=t->right;
			else
				break;
		}
		vector<int> ::iterator it;
		for(it=path.begin();it!=path.end();it++)
			cout<<*it<<" ";
	}

	//when a and b lie on different sides
	//find the path from ancestor to a then from that to b
	else{
		t=anc;
		//find path to a
		while(t){
			path.push_back(t->data);
			if(t->data>a){
				t=t->left;
			}
			else if(t->data<a){
				t=t->right;
			}
			else if(t->data==a){
				break;
			}
		}
		vector<int>::reverse_iterator itr;
		for(itr=path.rbegin();itr!=path.rend();itr++){
			cout<<*itr<<" ";
		}
		path.clear();

		//now search for b
		t=anc;
		//find path to a
		while(t){
			path.push_back(t->data);
			if(t->data>b){
				t=t->left;
			}
			else if(t->data<b){
				t=t->right;
			}
			else if(t->data==b){
				break;
			}
		}
		vector<int>::iterator it;
		for(it=path.begin()+1;it!=path.end();it++){
			cout<<*it<<" ";
		}
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
/*				3
			  /   \
			 -2     5
			/ \
		  -3   1
*/
	Node *root=createNode(3);
	root->right=createNode(5);
	root->left=createNode(-2);
	root->left->left=createNode(-3);
	root->left->right=createNode(1);

	findShortestPath(root,-3,5);
	return 0;
}
