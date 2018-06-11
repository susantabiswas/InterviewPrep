//Searches an element in a given Linked List through recursive method

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
	bool SearchElement(Node*,int);

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

bool List::SearchElement(Node *temp,int element)
{
    if(temp==NULL )         //if the list has ended
    	return false;
    if(temp->data==element)     //if a search has been found
    	return true;

    return SearchElement(temp->next,element);       //continue searching


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
	int element;
	List list1;

	for (int i = 0; i <4; ++i)
	{
		list1.InsertBegin(i);

	}
    list1.Display();

    cout<<"\nEnter Element to search\n";
    cin>>element;
    if(list1.SearchElement(list1.head,element))
        cout<<"Element Found";
    else
        cout<<"Element not Found";
	return 0;
}
