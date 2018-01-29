//implement Queue usibng linked list
#include<iostream>
using namespace std;

class Node
{

public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

class Queue
{
private:
	Node *front,*rear;
public:
	Queue(){front=rear=NULL;}
	void enqueue(int data);
	void dequeue();
	void display();
};

//for pushing the node in the rear
void Queue::enqueue(int data)
{
	try{
		//create the node
		Node *node=new Node(data);

		//when the queue is empty
		if(!rear)
		{
			front=rear=node;
			return;
		}
		//when the queue has some nodes
		else
		{
			rear->next=node;
			rear=node;
		}
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory Full !";
	}
}

//for deleting a node from queue
void Queue::dequeue()
{
	if(!front)
	{
		cout<<"Empty Queue\n";
		return;
	}
	else
	{
		Node *temp=front;
		front=front->next;
		cout<<temp->data<<" dequeued\n";
		delete temp;
	}
}

//displays the nodes of queue
void Queue::display()
{
	Node *temp=front;
	while(temp)
	{
		cout<<temp->data<<" ";
        temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	//create a queue
	Queue q;
	for (int i = 0; i < 10; ++i)
	{
		q.enqueue(i);
	}

	q.display();

	//dequeue elements
	for (int i = 0; i < 5; ++i)
	{
		q.dequeue();
	}

	q.display();
	return 0;

}
