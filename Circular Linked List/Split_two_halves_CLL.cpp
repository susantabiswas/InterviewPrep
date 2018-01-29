 //Split the Circular List in two halves

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next=NULL;
};

class CircularList
{
public:
	Node *head;		//head pointer

	CircularList(){ head=NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Split(Node**,Node**);
	void Display();
};

//allocates memory for creation of node
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

//Inserts the node in the beginning of list
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

//Splits the Circular Linked List in two halves
void CircularList::Split(Node **head1,Node **head2)
{
	//here "head" is the head of the list of object that called
	Node *slowptr=head;
	Node *fastptr=head->next;

	//if the list is empty or only one node exists
	if(head==NULL || head->next==NULL)
		return;

	//make the head1 of first list
	*head1=head;

	//using hare and tortoise algo. to traverse
	//when fastptr finishes traversal slowptr wil be in the mid
	while(fastptr->next->next!=head && fastptr->next!=head)
		{
			fastptr=fastptr->next->next;
			slowptr=slowptr->next;
		}

	//make the head of second list
	*head2=slowptr->next;

	//if list has odd nodes then fastptr->next equals head
	if(fastptr->next==head)
	{	//make the first list circular
		slowptr->next=*head1;

		//make the second list circular
		fastptr->next=*head2;
	}
	//if list has even nodes then fastptr->next->next equals head
	if(fastptr->next->next==head)
	{	//make the first list circular
		slowptr->next=*head1;

		//make the second list circular
		fastptr->next->next=*head2;
	}

}

//For displaying the nodes of the list
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
	CircularList list1;
	CircularList list2,list3;
	for (int i = 5; i >0; --i)
	{
		list1.InsertBegin(i);

	}
	list1.Display();

	list1.Split(&list2.head,&list3.head);
	cout<<"\n\nAfter Splitting:";
	list2.Display();
	list3.Display();
	return 0;
}
