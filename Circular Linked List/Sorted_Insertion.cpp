//Insertion of element in a sorted List such that the List remains sorted

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next=NULL;
};

class CircularList
{
private:
	Node *head;
public:
	CircularList(){ head=NULL; }
	Node* create(int);
	void InsertBegin(int);
	void InsertSorted(int);
	void Display();
};

//for allocating space for node creation
Node* CircularList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}

//insertion at beginning of list
void CircularList::InsertBegin(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
			//pointing the last node to the head node
			head->next=head;
		}
		else
		{
		    Node *temp=head;
		    //To find the last node
		    while(temp->next!=head)
                temp=temp->next;
            temp->next=node;

			node->next=head;

			head=node;
		}
	}
}

//insertion in sorted list such that it remains sorted
void CircularList::InsertSorted(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		//empty list
		if(head==NULL )
		{
			head=node;
			node->next=head;
			return;
		}
		//when data lies before head node
		if(head->data>dataItem)
		{
			//insert the new node in the second position
			//swap the data between the nodes
			int swap=head->data;
			head->data=node->data;
			node->data=swap;

			node->next=head->next;
			head->next=node;

			return;
		}
		//when data lies in the end or somewhere in between
		//start traversal of list till right position
		Node *temp=head;
		while(temp->next!=head && temp->next->data<dataItem)
		{
			temp=temp->next;
		}
		node->next=temp->next;
		temp->next=node;
	}
}

//for displaying the list
void CircularList::Display()
{
	cout<<"\nContents of the List :\n";
	Node *temp=head;

	do
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}while(temp!=head);
}

int main()
{
	CircularList List1;
	List1.InsertBegin(15);
	List1.InsertBegin(13);
	List1.InsertBegin(12);
	for (int i = 4; i>0; --i)
	{
		List1.InsertBegin(i);

	}

	List1.Display();

	List1.InsertSorted(10);
	List1.Display();
	return 0;
}
