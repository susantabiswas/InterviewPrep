//given a list containing even and odd numbers ,arrange them such that the even numbers are in the beginning
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
//check if the linked list is a palindrome or not
/*
push all the element then start from the first element and the last element using the stack top element
if at any moment both becomes unequal then not a palindrome
*/
bool isPalindrome(Node *head)
{
	Node *temp=head;
	stack<Node*> s;
	while(head)
	{
		s.push(head);
		head=head->next;
	}

	while(!s.empty())
	{
		if(temp->data !=(s.top())->data)
			return false;
		s.pop();
		temp=temp->next;
	}
	return true;
}

//arranges the even nodes in the beginning of odd nodes
void arrangeEven(Node *head)
{
	Node *prev,*odd,*even,*temp;
	prev=even=odd=NULL;
	temp=head;
	while(head)
	{
		if(head->data%2!=0)
		{
			odd=head;
			break;
		}
		head=head->next;
	}
	while(temp)
	{
		if(temp->data%2==0)
		{
			if(even==NULL)
			{
				even=temp;
				head=even;
				prev->next=temp->next;
			}
			else
			{
				even->next=temp;
				even=even->next;
				prev->next=temp->next;
			}
		}
		prev=temp;
		temp=temp->next;
	}
	even->next=odd;
}

int main()
{
	Node *head=NULL;
	insert(&head,1);
	insert(&head,3);
	insert(&head,2);
	insert(&head,7);
	insert(&head,4);
	insert(&head,6);
	insert(&head,5);
	cout<<"Initially:\n";
	display(head);
	arrangeEven(head);
	cout<<"After :\n";
	display(head);
	return 0;
}
