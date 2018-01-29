//find the level with the maximum sum

#include<iostream>
#include<queue>
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

//returns the level with maximum sum
int findMaxSumLevel(Node *root){
	if(root==NULL)
		return 0;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	Node *el=NULL;
	int level,cur_level=0;
	int curr_sum=0,max_sum=0;
	while(!q.empty()){
		el=q.front();
		q.pop();

		//whenever a level ends check if that level sum is greater than the maximum sum found 
		//far and reset the curr_sum to zero again
		if(el==NULL){
			++cur_level;
			if(curr_sum>max_sum){
				max_sum=curr_sum;
				level=cur_level;
				curr_sum=0;
			}
			if(!q.empty())
				q.push(NULL);
		}
		else{
			curr_sum+=el->data;

			//insert the left and right nodes if tehy exists
			if(el->left)
				q.push(el->left);
			if(el->right)
				q.push(el->right);
		}
	}
	return level;
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

	cout<<"level:"<<findMaxSumLevel(root);
	return 0;
}
