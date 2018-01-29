//Implement 'k' queues with a single array
/*
Space Efficient method:maintain three arrays .one for storing the next element
another for the front of queue of each of the 'k' queues and the last for storing the index of rear of 'k' queues.
NOTE:Space efficient only when the array is of some data type other than integer or char
*/
#include<iostream>
#include<climits>
using namespace std;

class kQueues
{
private:
    int *arr;   //for storing the k queues
    int *next;  //for storing the next top index and can also contain free array index
    int *front;       //for storing the index of front of each queue
    int *rear;		//for storing the rear of 'k' queues
    int n,k;        //n is total size ,k:no. of queues
    int free;       //contains the free index where an element can be enqueued
public:
    //constructor for creating the arrays
    kQueues(int ,int );
    //for inserting the elements in the queue
    void enqueue(int ,int);
    //for deleting elements from the queue
    int dequeue(int);
    //check whether the queue is empty or not
    bool isEmpty(int);
    //check whether the array is full or not
    bool isFull();
};

kQueues::kQueues(int n,int k)
{
    arr=new int[n];
    next=new int[n];
    front=new int[k];
    rear=new int[k];

    //initially each next element is used for storing the next free space index
    for (int i = 0; i < n; ++i)
    {
        next[i]=i+1;
    }
    next[n-1]=-1;

    //initially front of each queue is empty
    for (int i = 0; i < k; ++i)
    {
        front[i]=-1;
    }

    //initially rear of each queue is empty
    for (int i = 0; i < k; ++i)
    {
        rear[i]=-1;
    }

    //first free space index is arr[0] is itself
    free=0;
}


//checks whether the array is empty or not
bool kQueues::isEmpty(int sn)
{
    //when array is full free=-1
    return ((rear[sn]==-1));
}

//checks whether the array is full or not
bool kQueues::isFull()
{
    //when array is full free=-1
    return ((free==-1));
}

//data :the data to be enqueueed
//sn:queue number
void kQueues::enqueue(int data,int sn)
{
    //while the array is not full
    if(!isFull())
    {
        //give the free space index
        int i=free;
        //update free with new free space index
        free=next[i];

        //if the element is the first element of queue
        if(isEmpty(sn))
        	front[sn]=i;
        else
        //make next[i] point to its next index in queue
            next[rear[sn]]=i;

        next[i]=-1;
        //update rear with the current top position
        rear[sn]=i;

        arr[i]=data;
    }
    else
        cout<<"Array is Full !\n";
}

//dequeues the element from the queue
//sn:queue number
int kQueues::dequeue(int sn)
{
    //while the array is not empty
    if(!isEmpty(sn))
    {
        //current front index
        int i=front[sn];
        //make front point to the next front
        front[sn]=next[i];
        //give the current free space index to next[i]
        next[i]=free;
        //make the current element free
        free=i;
        return arr[i];
    }
    else
    {
        cout<<"Empty array !\n";
        return INT_MIN;
    }
}
int main()
{
    kQueues kq(10,3);
    //enqueue in queue 0
    for (int i = 0; i < 3; ++i)
    {
        kq.enqueue(i,0);
    }

    //enqueue in queue 1
    for (int i = 4; i < 7; ++i)
    {
        kq.enqueue(i,1);
    }

    int d;
    //dequeue from queue 0
    d=kq.dequeue(0);
    cout<<d<<" Dequeued from queue 0!\n";

    //dequeue from queue 1
    d=kq.dequeue(1);
    cout<<d<<" Dequeued from queue 1!\n";

    return 0;
}
