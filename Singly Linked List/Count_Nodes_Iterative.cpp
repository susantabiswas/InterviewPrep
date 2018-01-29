///To count the no. of nodes in a singly Linked list using iterative method


#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next=NULL;
};

class List
{
private:
	Node *head;
public:
	List(){ head=NULL; }
	int CountNodes();
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

int List::CountNodes()
{
	Node *temp=head;
	int count=0;		//for counting the no. of nodes

	while(temp!=NULL)
	{
		++count;
		temp=temp->next;
	}
    return count;
}

int main()
{
	List list1;			//list object

	for (int i = 0; i < 5; ++i)
	{
		list1.InsertBegin(i);			//making a list
	}

	cout<<"No. of elements are:"<<list1.CountNodes();
	return 0;
}
