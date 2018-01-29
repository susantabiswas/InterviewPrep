///To count the no. of nodes in a singly Linked list using recursion

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next=NULL;
};

class List
{
public:
    Node *head;
    List(){ head=NULL; }
	int CountNodes(Node**);
	Node *create(int);
	void InsertBegin(int);

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

//for counting the no. of nodes recursively
//Each time passing the next nodes's add. till we get NULL assigned to the node i.e the last node has been reached
int List::CountNodes(Node **temp)
{
	if(*temp==NULL)          //Base case
		return 0;
	else
	{

		return 1+CountNodes(temp->next);
	}
}

int main()
{
	List list1;			//list object

	for (int i = 0; i < 5; ++i)
	{
		list1.InsertBegin(i);			//making a list
	}

	cout<<"No. of elements are:"<<list1.CountNodes(list1.head);
	return 0;
}
