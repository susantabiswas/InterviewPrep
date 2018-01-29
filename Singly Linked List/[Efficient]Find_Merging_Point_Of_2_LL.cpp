//Find the merging point of two linked list
/*
find the length of the lists and then take out the difference of their lengths and
make the longer list traverse that difference ,then start the traversal from that point of one
list and starting point of another list,the first matching node is the merging node
node */
#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

//for creating the linked list
Node *create(int data)
{
	try
	{
		Node *node=new Node;
		node->data=data;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
		{return NULL;}
}

//for insertion
void insert(Node **head,int data)
{
	Node *node=create(data);
	if(node)
	{
		if(*head==NULL)
			*head=node;
		else
		{
			node->next=*head;
			*head=node;
		}
	}
	else
		return;
}

//for displaying the list
void display(Node *head)
{
	if(head==NULL)
		return;
	Node *temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

//for finding the length of the list
int getLength(Node *head)
{
	if(head==NULL)
		return 0;
	int c=0;
	while(head)
	{
		++c;
		head=head->next;
	}
	return c;
}

//for finding the merging point
Node* findMerge(Node *head1,Node *head2)
{
	//if the either of the list is null
	if(!head1 || !head2)
		return NULL;

	//find the lengths of both the lists
	int l1=getLength(head1);
	int l2=getLength(head2);
	int diff=abs(l1-l2);
	Node *temp=NULL;
	//for selecting the longer list
	//1 :the first list,0 :second list
	int choice=-1;
	//traverse the extra length
	if(l1>l2)
	{
		choice=1;
		temp=head1;
		int c=0;
		while(c++<diff)
			temp=temp->next;
	}
	else
	{
		choice=0;
		temp=head2;
		int c=0;
		while(c++<diff)
			temp=temp->next;
	}

	//traverse till the first matching node(merging node)
	if(choice==1)
	{
		while(head2 && temp)
		{
			if(head2==temp)
				return head2;
			head2=head2->next;
			temp=temp->next;
		}
	}
	else
	{
		while(head1 && temp)
		{
			if(head1==temp)
				return head1;
			head1=head1->next;
			temp=temp->next;
		}
	}
}

int main()
{
	Node *head1=NULL;
	Node *head2=NULL;
	for(int i=0;i<6;i++)
		insert(&head1,i);

	head2=create(9);
	head2->next=create(8);
	head2->next->next=head1->next->next->next;
	display(head1);
	cout<<endl;
	display(head2);
	cout<<endl;

	Node *result=findMerge(head1,head2);
	cout<<"Merged node:"<<result->data;
	return 0;
}
