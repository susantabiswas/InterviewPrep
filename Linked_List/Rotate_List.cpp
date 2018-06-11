//Rotates the List clockwise by k
/*Given linked list
1  2  3  4  5
k=3
Rotated Linked list
3  4  5  1  2
*/
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
	void Rotate(int );

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

//Rotates the list clockwise by k
/*traverse the list ,keep the address of Kth node and its previous node
and connect the last node to the first node*/
void List::Rotate(int k)
{
    Node *temp=head;			//for traversal
    Node *kprev=NULL;		//points to previous node of k-th node
    Node *prev=NULL;			//points to the previous node during traversal
    int c=1;

    //If the list is empty
    if(temp==NULL)
    	return;

    	//traverse the list
    while(temp!=NULL)
    {	//if counter 'c' is equal to the previous node of k
    	if(c==k-1)
    		kprev=temp;

		//Increment the counter c
		++c;

    	prev=temp;
    	temp=temp->next;
    }
    prev->next=head;
    head=kprev->next;
    kprev->next=NULL;
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

	for (int i = 5; i>0; --i)
	{
		list1.InsertBegin(i);

	}
    list1.Display();

    list1.Rotate(3);
    list1.Display();
	return 0;
}
