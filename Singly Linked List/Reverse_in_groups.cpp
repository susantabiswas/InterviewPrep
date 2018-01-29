//Reverses the Linked List in Groups of K nodes using iterative method
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
	void Reverse_group(int k);

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
void List::Reverse_group(int k)
{
	Node *temp=head;
	//If the List is empty
	if(temp==NULL)
	{
		cout<<"Empty List\n";
		return;
	}

	Node *prev=NULL;
	Node *first=NULL;
	//When the reversal involves head node
	int c=1;
	Node *nextNode=NULL;
	first=head;
	//Reversal the first 'k' nodes
	while(c++<=k && head!=NULL)
	{
		nextNode=head->next;
		head->next=prev;
		prev=head;
		head=nextNode;

	}
	//For placing the kth node in the head position
	first->next=nextNode;
	head=prev;

	//Previous node of the first element of new group
	Node *before=first;
	//Address of first node of next group
	temp=nextNode;

	//For the rest of the Linked List
	while(temp!=NULL)
	{
		c=1;
		//First node of the group
		first=temp;
		while(c++<=k && temp!=NULL)
		{
			nextNode=temp->next;
			temp->next=prev;
			prev=temp;
			temp=nextNode;
		}

		//For positioning the reversed group in the list
		//next pointer of Node before the first node of group points to the last node of group
		before->next=prev;
		//First node's next pointer points to the next node of following group
		first->next=nextNode;
		//Previous node for the next group
		before=first;
	}
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

    list1.Reverse_group(k);
    list1.Display();
	return 0;
}
