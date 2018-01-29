//find the intersection of two linked lists having sizes 'm' and 'n' respectively,which
//is not known beforehand.They merge at some point.Find the merge point
#include<iostream>
#include<cstdlib>
#include<unordered_map>
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

Node* findIntersectionMap(Node*h1 ,Node*h2){
	if(!h1 || !h2)
		return NULL;

	unordered_map<Node*,int> h;
	Node* t1 = h1;
	while(t1){
		if(h.find(t1)== h.end())
			h[t1] = t1->data;
		t1 = t1->next;
	}

	t1 = h2;
	while(t1){
		if(h.find(t1) !o= h.end())
			return t1;
		t1 = t1->next;
	}
}

Node* findIntersectionIter(Node* h1,Node* h2){
	if(!h1 || !h2)
		return NULL;

	//traverse the lists for their lengths
	Node* t = h1;
	int m = 0,n = 0;
	while(t){
		++m;
		t = t->next;
	}
	t = h2;
	while(t){
		++n;
		t = t->next;
	}

	//move the lists as neccessary
	if(m>n){
		int c = 1;
		while(c <= m-n && h1){
			c++;
			h1 = h1->next;
		}
	}
	else if(n>m){
		int c = 1;
		while(c <= n-m && h2){
			c++;
			h2 = h2->next;
		}
	}

	while(h1 && h2 && h1!=h2){
		h1 = h1->next;
		h2 = h2->next;
	}
	return h1;
}

main(){

	Node* h1 = NULL;
	for (int i = 0; i < 4; ++i)
	{
		insertNode(&h1,i);
	}

	Node* h2 = NULL;
	for (int i = 8; i < 15; ++i)
	{
		insertNode(&h2,i);
	}
	h1->next->next->next->next = h2->next->next;
	disp(h1);
	Node* ans = findIntersectionMap(h1,h2);
	cout<<ans->data<<endl;

	Node *res = findIntersectionIter(h1,h2);
	cout<<res->data<<endl;
}
