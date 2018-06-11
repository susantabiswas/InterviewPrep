-
//Merge two already sorted(increasing order) linked list in increasing order using recursion

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
	Node* Merge(Node*,Node*);

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


//temp1 is for list 1
//temp2 is for list 2
Node* List::Merge(Node *temp1,Node *temp2)								//Merge two Linked List
{
	Node *result=NULL;

	//base case
	if(temp1==NULL)
		return temp2;
	else if(temp2==NULL)
		return temp1;

	if(temp1->data<=temp2->data)
	{
		result=temp1;
		result->next=Merge(temp1->next,temp2);
	}
	else
	{
		result=temp2;
		result->next=Merge(temp1,temp2->next);
	}
	return result;
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

	//list 1 : 2->3->20
	list2.InsertBegin(20);
	list2.InsertBegin(3);
	list2.InsertBegin(2);

    list1.Display();
	list2.Display();

    list3.head=list2.Merge(list1.head,list2.head);
    list3.Display();
	return 0;
}
