//To detect if there is any loop in the Linked List or not

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
	bool DetectLoop();

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

//For detecting the presence of any loop in the list
//Done using Floyd's method
bool List::DetectLoop()
{
	Node *slowptr=head;
	Node *fastptr=head;

	while(slowptr!=NULL && fastptr!=NULL &&fastptr->next!=NULL)
	{
		//fastptr moves twice as fast as slowptr
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;

		//if a loop is there ,they are bound to meet
		if(slowptr==fastptr)
			return true;
	}
	return false;
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
	//cout<<list1.head->next;


	bool result=list1.DetectLoop();

	if(result)
    	cout<<"Loop present\n";
    else
    	cout<<"No loops present\n";

	return 0;
}
