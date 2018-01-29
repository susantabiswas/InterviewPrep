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
	void Reverse();

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

void List::Reverse()
{
    Node *temp=head;
	Node *temp1=NULL;
	Node *prev=NULL;
	while(temp!=NULL)
	{
        if(temp==head)
		{
			prev=temp;
			temp->next=prev;
			temp=prev->next;
        }
		else
		{
			//store the add. of current node in temporary variable
			temp1=temp;

			temp->next=prev;
			prev=temp;
			//place add. of next node in the 'temp' variable
			temp=temp1->next;
        }
	}
	head=prev;
    cout<<"*"<<head->data;
}

int main()
{
	List list1;

	for (int i = 0; i <4; ++i)
	{
		list1.InsertBegin(i);

	}


	list1.Display();

	list1.Reverse();
	cout<<"\nAfter Reversal";
	list1.Display();

	return 0;
}
