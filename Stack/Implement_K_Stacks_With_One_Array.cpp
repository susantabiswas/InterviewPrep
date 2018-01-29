//Implement 'k' stacks in a single array
/*
Space Efficient method:maintain two arrays .one for storing the previous element
and other for the top of stack of each of the 'k' stacks.
NOTE:Space efficient only when the array is of some data type other than integer or char
*/
#include<iostream>
#include<climits>
using namespace std;

class kStacks
{
private:
    int *arr;   //for storing the k stacks
    int *previous;  //for storing the previous top index and can also contain free array index
    int *top;       //for storing the index of top of each stack
    int n,k;        //n is total size ,k:no. of stacks
    int free;       //contains the free index where an element can be pushed
public:
    //constructor for creating the arrays
    kStacks(int ,int );
    //for inserting the elements in the stack
    void push(int ,int);
    //for deleting elements from the stack
    int pop(int);
    //check whether the stack is empty or not
    bool isEmpty(int);
    //check whether the array is full or not
    bool isFull();
};

kStacks::kStacks(int n,int k)
{
    arr=new int[n];
    previous=new int[n];
    top=new int[k];

    //initially each previous element is used for storing the next free space index
    for (int i = 0; i < n; ++i)
    {
        previous[i]=i+1;
    }
    previous[n-1]=-1;

    //initially top of each stack is empty
    for (int i = 0; i < k; ++i)
    {
        top[i]=-1;
    }

    //first free space index is arr[0] is itself
    free=0;
}


//checks whether the array is empty or not
bool kStacks::isEmpty(int sn)
{
    //when array is full free=-1
    return ((top[sn]==-1));
}

//checks whether the array is full or not
bool kStacks::isFull()
{
    //when array is full free=-1
    return ((free==-1));
}

//data :the data to be pushed
//sn:stack number
void kStacks::push(int data,int sn)
{
    //while the array is not full
    if(!isFull())
    {
        //give the free space index
        int i=free;
        //update free with new free space index
        free=previous[i];

        //give previous the index where the top was previously pointing to
        previous[i]=top[sn];
        //update top with the current top position
        top[sn]=i;

        arr[i]=data;
    }
    else
        cout<<"Array is Full !\n";
}

//pops the element from the stack
//sn:stack number
int kStacks::pop(int sn)
{
    //while the array is not empty
    if(!isEmpty(sn))
    {
        //current top index
        int i=top[sn];
        //make top point to the previous top
        top[sn]=previous[i];
        //give the current free space index to previous[i]
        previous[i]=free;
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
    kStacks ks(10,3);
    //push in stack 0
    for (int i = 0; i < 3; ++i)
    {
        ks.push(i,0);
    }

    //push in stack 1
    for (int i = 4; i < 7; ++i)
    {
        ks.push(i,1);
    }

    int p;
    //pop from stack 0
    p=ks.pop(0);
    cout<<p<<" Popped from stack 0!\n";

    //pop from stack 1
    p=ks.pop(1);
    cout<<p<<" Popped from stack 1!\n";

    return 0;
}
