//check whether the list is of even or odd length
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

void insertData(Node **head, int dataItem)			//for inserting the node in the of Begining list
{
	Node *node = create(dataItem);
	if (node != NULL)
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
		return;
	cout << head->data << " ";
	display(head->next);
	
}
//for checking whether the length of list is even or odd
void checkEvenOdd(Node *head)
{
	if (head == NULL)
		return;
	Node *fast = head;
	
	//if the fast pointer becomes NULL then the list is even else it is odd
	while (fast && fast->next)
	{
		fast = fast->next->next;
	}
	if (fast == NULL)
		cout << "\nEven\n";
	else
		cout << "\nOdd\n";
}



int main()
{
	Node *head=NULL;
	for (size_t i = 0; i < 11; i++)
	{
		insertData(&head, i);
	}
	//cout << head->next->next;
	display(head);
	checkEvenOdd(head);
	return 0;
}