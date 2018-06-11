//Split the Linked List in two halves

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
	void Split(Node**,Node**,Node*);

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

//For Splitting the Linked List in two halves
void List::Split(Node **temp1,Node **temp2,Node *head)
{
	int count=0;
	//Count the no. of nodes for splitting
	Node *temp=head;
	while(temp!=NULL)
	{
		++count;
		temp=temp->next;
	}

	//Split the list in count/2

	int i=1;
	//temp1 is the head pointer of the first list
	*temp1=head;
	temp=head;
	//traverse the list till count/2 then the first list ends and
	//its next node is the first element of next list pointed by temp2
	while(i<count/2)
	{
		++i;
		temp=temp->next;
	}
	//temp2 is the head pointer of the first list
	*temp2=temp->next;
	temp->next=NULL;
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
	List list1,list2,list3;

	//list 1 : 5->10->15
	list1.InsertBegin(15);
	list1.InsertBegin(10);
	list1.InsertBegin(5);
	list1.InsertBegin(20);
	list1.InsertBegin(3);
	list1.InsertBegin(2);
	cout<<"original List:";
    list1.Display();

    //Split list1 into two new lists list2 and list3
	list1.Split(&list2.head,&list3.head,list1.head);

	cout<<"\n\nAfter Splitting:";
   list2.Display();
   list3.Display();
	return 0;
}
