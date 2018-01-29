//find the size of cycle if that exists in a singly linked list
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class list{
private:
	Node *head;
public:
	list(){head=NULL;}
	void insert(int data);
	Node* create(int data);
	void makeCycle(int);
	int findSize();
};

Node* list::create(int data)
{
	try{
		Node *node=new Node;
		node->next=NULL;
		node->data=data;
		return node;
	}
	catch(bad_alloc xa)
		{return NULL;
		}
}

void list::insert(int data)
{
	Node *node=create(data);
	if(node){
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			node->next=head;
			head=node;
		}
	}
	else
		return;
}

void list::makeCycle(int k)
{
	int c=1;
	if(head==NULL)
		return;

	Node *t=head;
	Node *temp=NULL;
	while(t->next)
	{
		if(c==k)
			temp=t;

		t=t->next;
		++c;
	}
	t->next=temp;
}

int list::findSize()
{
	Node *slow,*fast;
	slow=fast=head;
	bool cycle=false;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			cycle=true;
			break;
		}
	}

	if(cycle)
	{
		int c=1;
		fast=fast->next;
		while(fast!=slow)
		{
			++c;
			fast=fast->next;
		}
		return c;
	}
	else
	{
		cout<<"No cycle found \n";
		return 0;
	}
}

int main()
{
	list ob;
	for (int i = 0; i < 5; ++i)
	 {
	 	ob.insert(i);
	 }

	ob.makeCycle(3);
	cout<<"Size of cycle is:"<<ob.findSize();
	return 0;
}
