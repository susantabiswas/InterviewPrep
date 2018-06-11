//print the linked list from end
/*
use recursion
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node* create(int localData)			//for creating a node
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

void insertData(Node **head,int dataItem)			//for inserting the node in the of Begining list
{
	Node *node = create(dataItem);
	if (node!=NULL)
	{
		if (*head == NULL)
		{
			*head = node;
			node->next = NULL;
		}
		else
		{
			node->next = *head;
			*head = node;
		}
	}
	else
	{
		cout << "Can't create node\n";
	}

}

//for displaying the list from end
void display(Node *head)
{
	if (head == NULL)
		return ;

	display(head->next);
   cout << head->data << " ";
}

int main()
{
	Node *head=NULL;
	for (size_t i = 0; i < 10; i++)
	{
		insertData(&head, i);
	}
   display(head);
	return 0;
}
