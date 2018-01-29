//Implement a queue using one stack
/*Stack1 is used for storing the elements.
  and we use recursion for dequeuing the elements
*/

#include<iostream>
#include<climits>
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
	public:
	custQueue(){topStack1=NULL;}
	void enqueue(int);	//Stack 1 is used for enqueue(storing) the elements
	int dequeue(Node*); 	//Recursion is used for dequeue operation
	Node *create(int ); //creates node
	void push(Node**,int);
	void display();	//for displaying the elements
	Node* returnHead(){return topStack1;}
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
int custQueue::dequeue(Node* tempStack1)
{
	static Node *prev=NULL;
	//if the stack is empty
	if(tempStack1==NULL)
	{
		cout<<"Empty Stack\n";
		return INT_MIN;
	}
	else if(tempStack1->next==NULL)	//when there is only one element or it is the last element
	{
		int d=tempStack1->data;
		//make previous node's next point to NULL
		prev->next=NULL;
		delete tempStack1;

		return d;
	}
	else
	{
		prev=tempStack1;
		return dequeue(tempStack1->next);
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
	int d;
	d=q.dequeue(q.returnHead());
	cout<<d<<" Dequeued \n";
	d=q.dequeue(q.returnHead());
	cout<<d<<" Dequeued \n";
	d=q.dequeue(q.returnHead());
	cout<<d<<" Dequeued \n";
	return 0;
}
