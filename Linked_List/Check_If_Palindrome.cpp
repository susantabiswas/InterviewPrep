//check if a linked list is a palindrome or not
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

int main()
{
	Node *head=NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,0);
	insert(&head,33);
	insert(&head,2);
	insert(&head,1);

	display(head);
	 if(isPalindrome(head))
	 	cout<<"\nPalindrome\n";
	 else
	 	cout<<"\nNot a Palindrome\n";
	return 0;
}
