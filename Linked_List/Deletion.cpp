//Deletion in Linked list

#include<iostream>
#include<cstdlib>
using namespace std;

//stucture for Node
struct Node{
	int data;
	Node *next;
};

//for Node creation
Node* createNode(int data){
	try{
		Node* node = new Node;
		if(!node)
			throw -1;

		node->data = data;
		node->next = NULL;
		return node;
	}
	catch(int e){
		if (e==-1){
			cout<<"Memory alocation error!";
			exit(1);
		}
	}
}

//for insertion
void insertBegin(Node** head,int data){
	Node *node = createNode(data);
	if(*head == NULL)
		*head = node;
	else{
		node->next = *head;
		*head = node;
	}
}

//for deletion at begining
void delBegin(Node** head){
	if(*head == NULL){
		cout<<"Underflow!";
	}
	else{
		Node* t = *head;
		*head = (*head)->next;
		delete t;
	}
}

//deletion at any position
void delPos(Node** head,int pos){
	//check for underflow
	if(*head == NULL){
		cout <<"Underflow!";
		return;
	}

	//check if deletion is to occur at 1st position or not
	if(pos==1){
		Node* t = *head;
		*head = (*head)->next;
		delete t;
	}
	else{
		int count = 1;
		Node* t = *head;
		while(t->next && count<pos-1){
			++count;
			t=t->next;
		}

		//check for out of bound
		if(count < pos-1 || t->next == NULL){
			cout<<"Posiiton out of bound";
			return;
		}

		Node* t1 = t->next;
		t->next = t->next->next;
		delete t1;
	}
}

//deletion at end
void delEnd(Node** head){
	Node* t = *head;
	Node* prev = NULL;
	while(t->next){
		prev = t;
		t = t->next;
	}
	prev->next = NULL;
	delete t;
}

//for display
void disp(Node *head){
	while(head){
		cout << head->data <<" ";
		head = head->next;
	}
	cout<<endl;
}

main(){
	Node *head = createNode(5);
	for(int i = 4; i>=0; i--)
		insertBegin(&head,i);

	disp(head);
	delPos(&head,6);
	disp(head);
	delEnd(&head);
	disp(head);
	delBegin(&head);
	delBegin(&head);
	delBegin(&head);
	delBegin(&head);
	delBegin(&head);
	delBegin(&head);

	disp(head);
}
