//insert an element in a sorted list

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
	void InsertEnd(int);
	void Display();
	void sortedInsert(int );
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

void List::sortedInsert(int data)
{
	Node *temp=NULL;
	if(head==NULL)
		return;

	Node *node=create(data);
	if(node)
	{
		temp=head;
		while(temp && temp->next)
		{
			if(node->data>=temp->data && node->data<=temp->next->data)
			{
				node->next=temp->next;
				temp->next=node;
				return;
			}
			temp=temp->next;
		}
		temp->next=node;
	}
}

int main()
{
	List list1;

	for (int i = 0; i <4; ++i)
	{
		list1.InsertEnd(i);
	}

	list1.InsertEnd(6);
	list1.Display();

	list1.sortedInsert(5);
	list1.Display();
	return 0;
}
