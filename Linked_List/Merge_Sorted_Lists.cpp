//Merge 2 sorted linked lists
#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

//linked list structure
//Node structure
struct Node{
	int data;
	Node *next;
};

//display function
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//for creation of node
Node *createNode(int data){
	try{
		Node *node = new Node;
		node->data = data;
		node->next = NULL;
		return node;
	}
	catch(exception& e){
		cout<<e.what();
		exit(1);
	}
}

void insertNode(Node** head,int data){
	Node* node = createNode(data);
	if(*head == NULL){
		*head = node;
	}
	else{
		node->next = *head;
		*head = node;
	}
}

//merge sorted lists
Node* mergeListsRec(Node* h1,Node* h2){
	if(!h1)
		return h2;
	if(!h2)
		return h1;
	Node *res = NULL;
	if(h1->data > h2->data){
		res = h2;
		h2 = h2->next;

	}
	else if(h1->data <= h2->data){
		res = h1;
		h1 = h1->next;

	}
	res->next = mergeListsRec(h1,h2);

	return res;

}

//merge sorted lists
Node* mergeListsIter(Node* h1,Node* h2){
	Node* prev = NULL;
	Node* head = NULL;

	if(h1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	head = h1->data<h2->data?h1:h2;
	while(h1 && h2){

		if(h1->data > h2->data){
			if(prev == NULL){
					prev = h2;
			}
			else{
				prev->next = h2;
			}
			prev = h2;
			h2 = h2->next;
		}
		else{
			if(prev == NULL){
					prev = h1;
			}
			else{
				prev->next = h1;
			}
			prev = h1;
			h1 = h1->next;
		}
	}

	if(h1){
			prev->next = h1;
	}
	if(h2){
			prev->next = h2;
	}

	return head;
}

int main(){
	Node* h1 = NULL;
	insertNode(&h1,9);
	insertNode(&h1,7);
	insertNode(&h1,4);
	insertNode(&h1,3);
	insertNode(&h1,1);

	disp(h1);

	Node* h2 = NULL;
	insertNode(&h2,6);
	insertNode(&h2,5);
	insertNode(&h2,3);
	insertNode(&h2,2);

	disp(h2);
	/*Node* res = mergeListsRec(h1,h2);
	disp(res);
	*/
	Node* res = mergeListsIter(h1,h2);
	disp(res);
	return 0;
}
