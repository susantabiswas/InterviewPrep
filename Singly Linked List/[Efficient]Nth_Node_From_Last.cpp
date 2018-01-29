//find the nth node from the last
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
public:
	Node(int data){this->data=data;
		next=NULL;}
};

class list
{
	Node *head;
public:
	list()
	{head=NULL;}
	void insert(int );
	Node* create(int );
	void display();
	int getNth(int);
};

Node* list::create(int data)
{
	try{
		Node *node=new Node(data);
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory Full!";
		return NULL;
	}
}

void list::insert(int data)
{
	Node *node=create(data);
	if(node)
	{
		if(head==NULL)
			head=node;
		else
		{
			node->next=head;
			head=node;
		}
	}
	else
		return;
}

void list::display()
{
	Node *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int list::getNth(int n)
{
	Node *t1,*t2;
	t1=t2=head;
	int c=1;
	if(head==NULL)
		return -1;
	while(c<n)
	{
		++c;
		t1=t1->next;
	}

	while(t1->next)
	{
		t1=t1->next;
		t2=t2->next;
	}
	return t2->data;
}

int main()
{
	list ob;
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		ob.insert(i);
	}
	cout<<endl;
	ob.display();
	cout<<endl;
	cout<<"NTH:"<<ob.getNth(3);
	return 0;
}
