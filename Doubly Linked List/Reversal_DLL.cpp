//Reverses a Doubly Linked List
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev=NULL;
	Node *next=NULL;
};

class DoublyList
{
	private:
		Node *head;
	public:
		DoublyList(){ head=NULL; }
		Node* create(int);
		void InsertBegin(int);
		void Display();
		void Reverse();
};

//for allocating space for node creation
Node* DoublyList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->prev=NULL;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}
//for insertion of node
void DoublyList::InsertBegin(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			node->next=head;
			head->prev=node;
			head=node;
		}
	}
}

//Reverses a Doubly Linked List
void DoublyList::Reverse()
{
	Node *nextptr=NULL;
	Node *temp=head;

	//traverse the list till the second last node
	while(temp->next!=NULL)
	{
		nextptr=temp->next;
		temp->next=temp->prev;
		temp->prev=nextptr;
		temp=nextptr;
	}
	//Now temp contains last node's add.
	head=temp;
	temp->next=temp->prev;
	temp->prev=NULL;
}


void DoublyList::Display()        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }

}
int main()
{
	DoublyList DoublyList1;

	for (int i = 0; i < 4; ++i)
	{
		DoublyList1.InsertBegin(i);

	}

	DoublyList1.Display();

	DoublyList1.Reverse();
	DoublyList1.Display();
	return 0;
}
