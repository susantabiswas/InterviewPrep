//Singly Linked List Implementation and its associated operations
//Insertion at:beginning,end and at any position in the list


#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class List
{
private:
	Node *head;				//head for the list
public:
	List() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Display();
	void InsertEnd(int);
	void InsertAnyPosition(int,int);

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

void List::InsertEnd(int dataItem)				//for inserting the node in the end of the list
{
	Node *node = create(dataItem);
	if (node != NULL)
	{
		if (head == NULL)
		{
			head = node;
		}
		else
		{
			Node*temp = head;
			while (temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = node;
		}
	}

}


void List::InsertAnyPosition(int dataItem,int position)			//For inserting node at any position in the List
{
	Node *node = create(dataItem);
	if (node != NULL)
	{
		if (head == NULL)
		{
			head = node;
		}
		else if (position == 1)
		{
			node->next = head;
			head = node;
		}
		else
		{
			Node *temp = head;
			int index = 1;
			while (temp->next!=NULL && index<position-1)
			{
				temp = temp->next;
				++index;
			}
			node->next = temp->next;
			temp->next = node;

		}
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

int main()
{
	List list1;

	for (int i = 0; i <4; ++i)
	{
		//list1.InsertBegin(i);
		list1.InsertEnd(i);
	}


	list1.Display();

	list1.InsertAnyPosition(99, 5);
	list1.Display();

	return 0;
}
