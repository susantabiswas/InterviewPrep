//To swap two nodes in a Linked List without swapping their data part,only the link part is to be swapped
//Also the data to be swapped is taken as per their occurrence in the List
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
	void Swap();
	void EffiecientSwap();

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
	if (node != NULL)
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
//First swap the previous pointers of the two nodes then their next pointers
//possible cases:when both have the same value
//either  of x and y is head
//both of them are adjacent to each other
//when both are not adjacent
//when both or either of them is absent in the list
void List::Swap()				//For swapping the nodes
{
	int x, y;
	cout << "Enter the data of nodes to swap\n";
	cin >> x >> y;

	Node *prev1=NULL,*prev2=NULL,*temp1=NULL,*temp2=NULL,*swapval=NULL;
	//if  X and Y are of same value
	if(x==y)
	{
		cout<<"same value\n";
		return;
	}

	//search for X
	temp1=head;
	while(temp1->data!=x && temp1!=NULL)
	{
		prev1=temp1;
		temp1=temp1->next;
	}

	//search for Y
	temp2=head;
	while(temp2->data!=y && temp2!=NULL)
	{
		prev2=temp2;
		temp2=temp2->next;
	}

	//check if either of the two values is absent
	if(temp1->data==NULL || temp1->data==NULL)
	{
		cout<<"Values not present\n";
		return;
	}

	//check whether X is head
	if(prev1==NULL)
	{

		head=temp2;
	}
	else
	{
		prev1->next=temp2;
	}

	//check whether Y is head
	if(prev2==NULL)
	{

		head=temp1;
	}
	else
	{
		prev2->next=temp1;
	}

	//swap the next pointers
	swapval=temp2->next;
	temp2->next=temp1->next;
	temp1->next=swapval;
	cout<<"Swapped\n";
}

//in the previous swap function there were two traversal going on for finding the X and Y respectively
//in this traversal is there only once
//We search through the list till we find either X or Y then we store that node's address and using temp2 traverse further
//till the next element to be swapped is found

void List::EffiecientSwap()
{
	int x, y;
	cout << "Enter the data of nodes to swap\n";
	cin >> x >> y;

	Node *prev1=NULL,*prev2=NULL,*temp1=NULL,*temp2=NULL,*swapval=NULL;

	//if X and Y have the same value
	if(x==y)
	{
		cout<<"same value\n";
		return;
	}

	//start traversal
	temp1=head;
	while(temp1!=NULL)
	{
		//If either X or Y is found
		if(temp1->data==x || temp1->data==y)
		{
			//For the case when Y comes before X in the list
			if(temp1->data==y)
			{
				int swap=x;
				x=y;
				y=swap;
			}

			//store the next add. of X
			temp2=temp1->next;
			prev2=temp1;

			//Search for Y and continue traversing after X node's position
			while(temp2!=NULL && temp2->data!=y)
			{
				prev2=temp2;
				temp2=temp2->next;
			}

			//Y has been found
			if(temp2!=NULL)
			{
				//check for any head pointer case
				if(prev1==NULL)
				{
					cout<<"Swapped!\n";
					//swap the previous pointers of the nodes
					head=temp2;
					prev2->next=temp1;

					//swap the next pointers of the nodes
					swapval=temp2->next;
					temp2->next=temp1->next;
					temp1->next=swapval;
				}
				//Neither X  nor Y is in head position
				else
				{
					cout<<"Swapped!\n";
					//swap the previous pointers of the nodes
					prev1->next=temp2;
					prev2->next=temp1;

					//swap the next pointers of the nodes
					swapval=temp2->next;
					temp2->next=temp1->next;
					temp1->next=swapval;
				}
			}
			else
			{
				cout<<"element not present\n";
				return;
			}

		}

		prev1=temp1;
		temp1=temp1->next;
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
	cout << endl;
}

int main()
{
	int element;
	List list1;

	for (int i = 0; i <6; ++i)
	{
		list1.InsertBegin(i);

	}
	list1.Display();

	//list1.Swap();
	list1.EffiecientSwap();
	list1.Display();
	return 0;
}

