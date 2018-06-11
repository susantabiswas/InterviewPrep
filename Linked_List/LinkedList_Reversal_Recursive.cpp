//Reverses the elements in a given Linked List recursively

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class List
{
public:
	Node *head;				//head for the list

	List() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Display();
	void Reverse(Node*,Node*);

};


Node* List::create(int localData)			//for creating a node
{

	try {

		Node *node = new Node;
		if (node == NULL)
		{
			cout << "Allocation failure\n";
		}

		node->data = localData;
		node->next = NULL;
		return node;
	}
	catch (bad_alloc xa)
	{
		cout << "Allocation failure\n";
		return NULL;
	}

}

void List::InsertBegin(int dataItem)			//for inserting the node in the of Begining list
{
	Node *node = create(dataItem);
	if (node!=NULL)
	{
		if (head == NULL)
		{
			head = node;
			node->next = NULL;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	else
	{
		cout << "Can't create node\n";
	}

}

void List::Display()						//for displaying the list
{
	cout << "\nContents of List:\n";
	Node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void List::Reverse(Node *prev,Node *temp)            //Reverses the List elements
{
   if(temp==NULL)		//base case when the list has ended
   {
   	head=prev;
   	return;
   }

   Node *nextNode=temp->next;
   temp->next=prev;
   prev=temp;
   Reverse(prev,nextNode);
}

int main()
{
	List list1;

	for (int i = 0; i <5; ++i)
	{
		list1.InsertBegin(i);

	}


	list1.Display();

	list1.Reverse(NULL,list1.head);
	cout<<"\nAfter Reversal";
	list1.Display();

	return 0;
}
