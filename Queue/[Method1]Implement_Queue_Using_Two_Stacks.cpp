//Implement a queue using two stacks
/*Stack1 is used for storing the elements.
  Stack2 is used for popping the elements
*/

#include<iostream>
using namespace std;

//for creating nodes
class Node
{
	public:
	int data;
	Node *next;
};

class custQueue
{
private:
    Node *topStack1;	//topStack1 is the top pointer of stack 1
	Node *topStack2;	//topStack2 is the top pointer of stack 2
public:
	custQueue(){topStack1=topStack2=NULL;}
	void enqueue(int);	//Stack 1 is used for enqueue(storing) the elements
	void dequeue(); 	//Stack 2 is used for dequeue operation
	Node *create(int ); //creates node
	void push(Node**,int);
	void display();	//for displaying the elements
};

Node* custQueue::create(int data)
{
	try
	{
		Node *node=new Node;
		node->data=data;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory full !\n";
		return NULL;
	}
}

void custQueue::push(Node **head,int data)
{
	Node *node=create(data);
	if(node!=NULL)
	{
		//when the stack is empty
		if(*head==NULL)
		{
			*head=node;
		}
		else
		{
			node->next=*head;
			*head=node;
		}
	}
}

//for enqueuing data elements
void custQueue::enqueue(int data)
{
	push(&topStack1,data);
}

//for dequeuing elements
void custQueue::dequeue()
{
	//when both the stacks are empty then error
	if(topStack1==NULL && topStack2==NULL)
	{
		cout<<"Error !\n";
		return;
	}

	//if there is only one element
	else if(topStack1->next==NULL)
	 {
		Node *t=topStack1;
		topStack1=NULL;
		delete t;
	}

	//when stack2 is empty
	//fill it with stack 1 elements,so that stack 2 can be used for dequeuing
	else if(topStack2==NULL)
	{
		Node *t=topStack1;
		while(t!=NULL)
		{
			push(&topStack2,t->data);
			t=t->next;
		}
		//dequeue the first element
		t=topStack2;
		topStack2=topStack2->next;
		cout<<t->data <<"Dequeued \n";
		delete t;
	}
	//dequeue the element
	else
	{
		Node *t=topStack2;
		topStack2=topStack2->next;
		cout<<t->data <<"Dequeued \n";
		delete t;
	}
}

void custQueue::display()
{
	Node *temp=topStack1;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	/* Create a queue with items 1 2 3*/
   custQueue q;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);

	q.display();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	return 0;
}
