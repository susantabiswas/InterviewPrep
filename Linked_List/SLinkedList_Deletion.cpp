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
	void DeleteBegin();
	void DeleteEnd();
	void DeleteAnyPosition();

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

void List::DeleteBegin()				//For deleting the first node from the list
{
	if(head==NULL)
	{
		cout<<"Empty List\n";
	}
	else
	{
		Node *temp=head;
		head=head->next;
		delete temp;
	}
}

void List::DeleteEnd()						//For Deleting the node from the End
{
	if(head==NULL)
	{
		cout<<"Underflow!!\n";

	}
	else
	{
		Node *temp=head;
		Node *previous=NULL;
		while(temp->next!=NULL)
		{
			previous=temp;
			temp=temp->next;
		}
		previous->next=NULL;
		delete temp;
	}
}

void List::DeleteAnyPosition()					//For deleting the node from any position
{

	if(head==NULL)
	{
		cout<<"Underflow!!\n";

	}

	else
	{
		int position,index=1;
		cout<<"\nEnter the Position of Node to delete\n";
		cin>>position;

		Node*temp=head;
		Node *previous=NULL;

		if(position==1)             //when first node is to be deleted
        {
            Node *temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            while(temp->next!=NULL && index<position)
            {
                ++index;
                previous=temp;
                temp=temp->next;
            }
            previous->next=temp->next;
            delete temp;
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

	list1.InsertAnyPosition(99, 3);
	list1.Display();

	//list1.DeleteBegin();
	//list1.DeleteEnd();
	list1.DeleteAnyPosition();

	list1.Display();
	return 0;
}
