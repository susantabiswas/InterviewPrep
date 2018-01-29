//Reverses the Linked List in Groups of K nodes using Recursion
/*Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3
Output:  3->2->1->6->5->4->8->7->NULL.
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
public:
    Node *head;				//head for the list

	List() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Display();
	Node* Reverse_group(int k,Node*,Node*);

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

//Reverses the Linked List in group of 'k' nodes
//Returns the new head pointer
Node* List::Reverse_group(int k,Node*prev,Node*head)
{
	//base case
	//If the List is empty
	if(head==NULL)
	{
		return NULL;
	}
	Node *first=head;
	Node *nextNode=NULL;
	int c=1;
	while(c++<=k && head!=NULL)
	{
		nextNode=head->next;
		head->next=prev;
		prev=head;
		head=nextNode;
	}

	//if the list is not empty
	first->next=Reverse_group(k,prev,nextNode);


	//return the add. of first node of the group
	return prev;
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
}

int main()
{
	int k;
	List list1;

	for (int i = 8; i >0;--i)
	{
		list1.InsertBegin(i);

	}
    list1.Display();

    cout<<"\nEnter the value of K\n";
    cin>>k;

    List list2;
    list2.head=list1.Reverse_group(k,NULL,list1.head);
    list2.Display();
	return 0;
}
