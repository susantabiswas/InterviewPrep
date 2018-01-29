//Implement Queue using Array.
/* Array is implemented in Circular Manner
*/
#include<iostream>
using namespace std;

class Queue
{
private:
	int *arr;
	int rear,front,size,qCapacity;
public:
	Queue(int capacity);
	bool isFull();
	bool isEmpty();
	void enqueue(int data);
	void dequeue();
	void display();
	int getSize();
};

//constructor
Queue::Queue(int capacity)
{
	//array for queue implementation
	arr=new int[capacity];
	qCapacity=capacity;
	size=0;
	//rear and front
	rear=qCapacity-1;
	front=0;

}

//returns the size of queue
int Queue::getSize()
{
    return size;
}

//checks whether  the queue is empty or not
bool Queue::isEmpty()
{
    return((size==0)?true:false);
}

//checks whether the queue is full or not
bool Queue::isFull()
{
	return(size==qCapacity)?true:false;
}

//displays the queue elements
void Queue::display()
{
    cout<<endl;
    //when the queue is non-empty
	if(!isEmpty())
	{
		for ( int i = front%qCapacity ; i <=rear%qCapacity; ++i)
		{
			cout<<arr[i]<<" ";
		}
	}
}

//for adding elements to the queue
void Queue::enqueue(int data)
{
	//check whether the queue is full or not
	if(!isFull())
	{
		rear=(1+rear)%qCapacity;
		arr[rear]=data;
		++size;
	}
	else
        cout<<"Queue Full\n";
}

//for deleting an element from the queue
void Queue::dequeue()
{
	//check whether the queue is empty or not
	if(!isEmpty())
	{
		cout<<endl<<front<<" dequeued";
		++front;
		//change the queue size
		--size;
	}
	else
        cout<<"Empty queue\n";
}

int main()
{
	//make a queue of 10 elements
	Queue q(10);

    for (int i = 0; i < 10; ++i)
	{
		q.enqueue(i);
	}

	//display the queue elements
	q.display();

    //dequeue queue elements
	for (int i = 0; i < 5; ++i)
		q.dequeue();

	q.display();
	return 0;
}
