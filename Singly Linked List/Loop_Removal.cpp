//To remove any loop present in the Linked List

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
	void RemoveLoop();
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

void List::InsertBegin(int dataItem)			//for inserting the node in the of Beginning list
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

//For removing the presence of any loop in the list
//Detection Done using Floyd's method
void List::RemoveLoop()
{
	Node *slowptr=head;
	Node *fastptr=head;

	//Find whether loop is present or not
	while(fastptr!=NULL &&fastptr->next!=NULL)
	{
		//fastptr moves twice as fast as slowptr
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;

		//if a loop is there ,they are bound to meet
		if(slowptr==fastptr)
			{
				cout<<"Loop present\n";
				//Points to the intersection node
				Node *intersection=slowptr;

				//move slowptr from head node and fastptr from the intersection node
				//they will meet at the beginning node of the loop
				slowptr=head;

				//traverse till they reach the beginning node of loop
				//their next node will be pointing the same node
				while(slowptr->next!=fastptr->next)
				{
					//move both slowptr and fastptr at the same pace
					slowptr=slowptr->next;
					fastptr=fastptr->next;
				}

				//remove the loop by making the next of last node  NULL
				fastptr->next=NULL;
				cout<<"Loop removed\n";
				return;

			}

	}
		cout<<"Loop absent\n";
}

void List::Display()						//for displaying the list
{
	cout << "\nContents of List:\n";
	Node*temp = head;
	while (temp != NULL )
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	List list1;

	//list 1 : 5->10->15
	list1.InsertBegin(15);
	list1.InsertBegin(10);
	list1.InsertBegin(5);
	//Creating a loop
	list1.head->next->next->next=list1.head->next;

	//list1.Display();

	list1.RemoveLoop();
	return 0;
}
