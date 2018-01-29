//Merge Sort on Doubly Linked List

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

class DoublyList
{
public:
	Node *head;				//head for the list

	DoublyList() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Display();
	Node* Merge(Node**,Node**);
	void MergeSort(Node **);
	void Split(Node**,Node**,Node*);

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


//temp1 is for list 1
//temp2 is for list 2
Node* DoublyList::Merge(Node **temp1,Node **temp2)								//Merge two Linked List
{
	if(*temp1==NULL)		//When list 1 is empty
		return *temp2;
	if(*temp2==NULL)		//When list 2 is empty
		return *temp1;
	if(*temp1==NULL && *temp2==NULL)	//When both the lists are empty
		return NULL;

	Node *result=NULL,*prevnode=NULL;

	//Head case:to decide the node to which the head pointer will point
	if((*temp1)->data>=(*temp2)->data)
	{
		result=*temp2;
		prevnode=*temp2;
		(*temp2)=(*temp2)->next;

	}
	else
	{
		result=*temp1;
		prevnode=*temp1;
		*temp1=(*temp1)->next;
	}

	//traverse the rest of the two lists
	while(*temp1!=NULL && *temp2!=NULL)
	{
		if((*temp1)->data>=(*temp2)->data)
		{
			prevnode->next=*temp2;
			(*temp2)->prev=prevnode;
			prevnode=*temp2;
			*temp2=(*temp2)->next;
		}
		else
		{
			prevnode->next=*temp1;
			(*temp1)->prev=prevnode;
			prevnode=*temp1;
			*temp1=(*temp1)->next;
		}
	}

	//if either of the two lists become empty

		//when list 1 is empty
		if(*temp1==NULL && *temp2!=NULL)
		{
			prevnode->next=*temp2;
			(*temp2)->prev=prevnode;
			return result;
		}
		//when list 2 is empty
		if(*temp2==NULL && *temp1!=NULL)
		{
			prevnode->next=*temp1;
			(*temp1)->prev=prevnode;
			return result;
		}
}


//For Splitting the Linked List in two halves
void DoublyList::Split(Node **temp1,Node **temp2,Node *head)
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
	(*temp2)->prev=NULL;
	temp->next=NULL;
}


//For doing the Merge Sort on Singly Linked List
void DoublyList::MergeSort(Node **head)
{
	//If the list is empty or only one node is present
	if (*head==NULL || (*head)->next==NULL)
	{
		return;
	}

	//Split the List in two halves l1 and l2
	Node dummy;
	Node *l1=&dummy;
	Node *l2=&dummy;
	//Split function splits the list in two parts
	Split(&l1,&l2,*head);

	//recursively sort the rest of the list
	MergeSort(&l1);
	MergeSort(&l2);

	*head=Merge(&l1,&l2);

}

void DoublyList::Display()						//for displaying the list
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
	DoublyList list1;

	//list 1 : 2->3->20->5->10->15
	list1.InsertBegin(15);
	list1.InsertBegin(10);
	list1.InsertBegin(5);
	list1.InsertBegin(20);
	list1.InsertBegin(3);
	list1.InsertBegin(2);

	cout<<"Before Sorting:";
	list1.Display();

	list1.MergeSort(&list1.head);

   cout<<"\n\nAfter Sorting:";
   list1.Display();
	return 0;
}
