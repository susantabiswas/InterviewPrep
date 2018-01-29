//finds the nth node from the end of the linked list
#include<iostream>
using namespace std;

//for creating the nodes of list
class Node{
	public:
	int data;
	Node *next;

	Node(int i){data=i;next=NULL;}
};

class list
{
	public:
	Node*head;

	list(){head=NULL;}
	Node* create(int );
	void insert(int);
	int getNthEnd(Node*,int);
	void display();
};

//for creating a node
Node* list::create(int data)
{
	try{
		Node *node=new Node(data);
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory full !\n";
		return NULL;
	}
}

//for inserting nodes to the list
void list::insert(int data)
{
	//create a node
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


int list::getNthEnd(Node *head,int n)
{
	static int c=-1;
	if(head==NULL)
	{
		c=1;
		return -1;
	}

	int nth=getNthEnd(head->next,n);

	if(c==n)
	{
		++c;
		return head->data;
	}
	++c;
	return nth;
}

void list::display()
{
	Node *temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	list ob;
	for (int i = 0; i < 10; ++i)
	{
		ob.insert(i);
	}
	cout<<endl;
	ob.display();
	cout<<endl;
	cout<<ob.getNthEnd(ob.head,3);
	return 0;
}
