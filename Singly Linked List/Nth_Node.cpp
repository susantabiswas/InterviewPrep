//To find the nth node of a given linkde list
//input :index of element to show
//output:element of that index 

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};


//For creating a new node
Node *create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory allocation failed!!\n";
	}
}

//For inserting the node
void Insert(Node **ref_head,int dataItem)
{
	Node *node=create(dataItem);
	if(node)
	{
		if(*ref_head==NULL)
		{
			*ref_head=node;
		}
		else
		{
			node->next=*ref_head;
			*ref_head=node;
		}
	}
}

void NthNode(Node *temp,int index)
{
	int i=0;		//for index
	while(temp!=NULL && i<index)
	{
		temp=temp->next;
		++i;
	}
	if(temp)
	{
		cout<<temp->data;
	}
	else
	{
		cout<<"Entered index out of range\n";

	}

}
void Display(Node *temp)
{
	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	int index=0;
	struct Node *head=NULL;

	for (int i = 0; i < 5; ++i)
	{
		Insert(&head,i);
	}

	Display(head);

	cout<<"Enter the index of element to see\n";
	cin>>index;
	NthNode(head,index);
}
