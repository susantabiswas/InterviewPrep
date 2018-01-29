//Check the given number 'x' exists as a sum of two numbers in a given array of elements
/*We store all the elements of the array ,then check for each element a[i] ,whether x-a[i] exist or not*/
//Hashing using Separate Chaining
#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	Node *next;
	int data;
};

class Hash
{
private:
	//Hash table
	Node *h[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; ++i)
			h[i]=NULL;
	}
	//for inserting the hash keys
	void insertHashVal(int data);
	//for searching the keys in the hash table
	bool search(int data);
	//for mapping the index for a dataing value ,required in hash table
	int hashFunction(int);
	//for inserting the keys in front of the linked list
	void push(int,int);
	//checks whether the number exists as sum of two numbers or not
	bool checkSum(int arr[],int n,int x);

};

void Hash::push(int in,int data)
{
	try{
		Node *node=new Node;
		node->data=data;
		node->next=NULL;

		if(h[in]==NULL)
		{
			h[in]=node;
		}
		else
		{
			node->next=h[in];
			h[in]=node;
		}

	}
	catch(bad_alloc xa)
	{
		cout<<"Out of memory!!";
		return;
	}

}

//hash function
int Hash::hashFunction(int data)
{
	return ((int)abs(data))%7;
}

//for insertion of keys
void Hash::insertHashVal(int data)
{
	int in=hashFunction(data);
	push(in,data);
}

bool Hash::search(int data)
{
	int in=hashFunction(data);
	Node *temp=h[in];
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->data==data)
			{
				return true;
			}
		temp=temp->next;
	}
	return false;
}

//checks whether the number exists as sum of two numbers or not
bool checkSum(int arr[],int n,int x)
{
	Hash ob;
	//insert the hash keys
	for (int i = 0; i < n; ++i)
	{
		ob.insertHashVal(arr[i]);
	}

	//check whether x-arr[i] is there or not,
	//if it is there then sum has been found
	//else sum is not there
	for (int i = 0; i < n; ++i)
	{
		if(ob.search(x-arr[i]))
			return true;
	}
	return false;
}

int main()
{
	int arr[] = {1, 4, 45, 6, 10, -8};
    int x = 116;

	int n=sizeof(arr)/sizeof(int);

	if(checkSum(arr,n,x))
		cout<<"Sum found !!\n ";
	else
		cout<<"Sum not found !\n";

	return 0;
}
