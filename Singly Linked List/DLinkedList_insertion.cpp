//Doubly Linked List Implementation and its associated operations
//Insertion at:beginning,end and at any position in the list


#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev=NULL;
	Node *next=NULL;
};

class DoublyList
{
	private:
		Node *head;
	public:
		DoublyList(){ head=NULL; }
		Node* create(int);
		void InsertBegin(int);
		void Display();
		void InsertEnd(int);
		void InsertAnyPosition(int,int);

};

Node* DoublyList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->prev=NULL;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}

void DoublyList::InsertBegin(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			node->next=head;
			head->prev=node;
			head=node;
		}
	}
}

void DoublyList:: InsertEnd(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=node;
			node->prev=temp;

		}
	}
}

void DoublyList:: InsertAnyPosition(int dataItem,int position)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			if(position==1)
			{
				node->next=head->next;
                head=node;
			}
			else
			{
				int index=1;
				Node *temp=head;
				while(temp->next!=NULL && index <position-1)
				{
					temp=temp->next;
					++index;
				}
				//linking the new node to the previous and next node at that position
				node->next=temp->next;
				node->prev=temp;

                if(temp->next!=NULL)
                    {
                        (temp->next)->prev=node;
                         temp->next=node;
                    }
                else                    //When the position is the LAst position in the list
                {
                    temp->next=node;
                }


			}
		}
	}
}

void DoublyList::Display()        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }

}
int main()
{
	DoublyList DoublyList1;

	for (int i = 0; i < 4; ++i)
	{
		DoublyList1.InsertBegin(i);

	}
	DoublyList1.Display();
	for (int i = 55; i < 99; i+=11)
	{
		DoublyList1.InsertEnd(i);
	}
	DoublyList1.Display();

	DoublyList1.InsertAnyPosition(100,9);
	DoublyList1.Display();
	return 0;
}
