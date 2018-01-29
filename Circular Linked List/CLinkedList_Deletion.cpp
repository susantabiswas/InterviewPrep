#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next=NULL;
};

class CircularList
{
private:
	Node *head;
public:
	CircularList(){ head=NULL; }
	Node* create(int);
	void InsertBegin(int);
	void InsertEnd(int);
	void InsertAnyPosition(int,int);
	void Display();
	void DeleteBegin();
	void DeleteEnd();
	void DeleteAnyPosition();
};

Node* CircularList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}

void CircularList::InsertBegin(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
			//pointing the last node to the head node
			head->next=head;
		}
		else
		{
		    Node *temp=head;
		    //To find the last node
		    while(temp->next!=head)
                temp=temp->next;
            temp->next=node;

			node->next=head;

			head=node;
		}
	}
}

void CircularList::InsertEnd(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
			//pointing the last node to the head node
			head->next=head;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=node;
			node->next=head;


		}
	}
}

void CircularList::InsertAnyPosition(int dataItem,int position)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
			//pointing the last node to the head node
			head->next=head;
		}
		else
		{
			if(position==1)
			{
				Node *temp=head;
                //To find the last node
                while(temp->next!=head)
                    temp=temp->next;
                temp->next=node;

                node->next=head;

                head=node;
			}
			else
			{
				int index=1;
				Node *temp=head;
				while(temp->next!=head && index <position-1)
				{
					temp=temp->next;
					++index;
				}

				node->next=temp->next;
				temp->next=node;

			}
		}
	}
}


void CircularList::Display()
{
	cout<<"\nContents of the List :\n";
	Node *temp=head;

	do
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}while(temp!=head);
}

void CircularList::DeleteBegin()
{
	if(head==NULL)
	{
		cout<<"Underflow!!!\n";
	}
	else
	{
		Node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}

		//pointing the last node to the second node in the list
		temp->next=head->next;
		//Storing the address of the first node
		temp=head;

		//pointing the head pointer to the second node
		head=head->next;

		//deleting the first node
		delete temp;

	}
}

void CircularList::DeleteEnd()
{
	if(head==NULL)
	{
		cout<<"Underflow!!!\n";
	}
	else
	{
		Node *temp=head;
		Node *prev=NULL;

		//traverse till the last node
		while(temp->next!=head)
		{
			prev=temp;
			temp=temp->next;
		}
		//pointing the second last node to the head node
		prev->next=head;

		//deleting the last node
		delete temp;

	}
}

void CircularList::DeleteAnyPosition()
{
	if(head==NULL)
	{
		cout<<"Underflow!!!\n";
	}
	else
	{
	    int position;
	    cout<<"Enter the position of node to delete \n";
	    cin>>position;
		if(position==1)
		{
			Node *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}

			//pointing the last node to the second node in the list
			temp->next=head->next;
			//Storing the address of the first node
			temp=head;

			//pointing the head pointer to the second node
			head=head->next;

			//deleting the first node
			delete temp;
		}
		else
		{
			int index =1;
			Node *temp=head;
			Node *prev=NULL;

			//traverse till that position
			while(temp->next!=head && index<position)
			{
				++index;
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;

			//deleting the required node
			delete temp;

		}
	}
}

int main()
{
	CircularList List1;

	for (int i = 0; i < 4; ++i)
	{
		List1.InsertBegin(i);

	}
	List1.Display();
	for (int i = 55; i < 99; i+=11)
	{
		List1.InsertEnd(i);
	}
	List1.Display();

	List1.InsertAnyPosition(100,9);
	List1.Display();

	cout<<"\n\nDeletion from begining:";
	List1.DeleteBegin();
	List1.Display();

	cout<<"\n\nDeletion from End:";
	List1.DeleteEnd();
	List1.Display();

	cout<<"\n\nDeletion from Any position:";
	List1.DeleteAnyPosition();
	List1.Display();

	return 0;
}
