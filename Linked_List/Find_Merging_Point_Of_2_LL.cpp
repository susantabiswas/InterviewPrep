//Find the merging point of two linked list
/*
use stacks for storing both the lists and then pop the elements till the elements are not equal
*/
#include<iostream>
#include<stack>
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

//for finding the merging point
Node* findMerge(Node *head1,Node *head2)
{
	//store the addresses of nodes in stacks
	stack<Node*> s1,s2;
	while(head1)
	{
		s1.push(head1);
		head1=head1->next;
	}
	while(head2)
	{
		s2.push(head2);
		head2=head2->next;
	}

	//for storing the previous top
	Node *s;
	s=s1.top();
	while(!s1.empty() && !s2.empty())
	{
		//pop the stacks till we get the first different element
		if(s1.top()!=s2.top())
			return s;
		s=s1.top();
		s1.pop();
		s2.pop();
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
