//Find the  Union and Intersection of two Linked Lists
/*This solution uses Hashing */
#include<iostream>
using namespace std;

//for making nodes of linked list
struct  Node
{
	Node *next;
	int data;
};

class List
{
private:
	static Node *h[10];
public:
    Node *head;
    //constructor
	List()
	{
		head=NULL;
	}

	void printHashTable();
	bool search(int);
	void init_hashTable();
	void push(Node**,int);
	void display();
	int hashFunction(int);
	void hashInsert(int);
	void Union(List&,List&);
	void intersection(List&,List&);
};
//define static data member
Node* List::h[10];

//for initialising the hash table
void List::init_hashTable()
{
	for (int i = 0; i < 10; ++i)
	{
		h[i]=NULL;
	}
}

//for pushing keys in the linked list
void List::push(Node **head,int val)
{
	try{
		Node *node=new Node;
		node->data=val;
		node->next=NULL;

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
	catch(bad_alloc xa)
	{
		cout<<"Out of memory!!";
		return;
	}

}

//hash function
int List::hashFunction(int val)
{
	return val%7;
}

//for insertion of keys
void List::hashInsert(int val)
{
	int in=hashFunction(val);
	push(&h[in],val);
}

//for searching the keys in the hash table
bool List::search(int val)
{
	int in=hashFunction(val);
	Node *temp=h[in];
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->data==val)
			{
				return true;
			}
		temp=temp->next;
	}
	return false;
}



//prints the key value pairs of hash table
void List::printHashTable()
{
	Node *temp;
	for (int i = 0; i < 10; ++i)
	{
		if(h[i]!=NULL)
		{
			temp=h[i];
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	}
	cout<<endl;
}

//for finding the union
void List::Union(class List &ob1,class List &ob2)
{
	//now insert only those elements of second list which are already not in the hash table
    Node*temp=ob2.head;
    while(temp!=NULL)
    {
    	if(!search(temp->data))
    		hashInsert(temp->data);
        temp=temp->next;
    }

    cout<<"\nUnion:"<<endl;
    //print the hash table contents
    printHashTable();
}

//for finding the intersection
void List::intersection(List &ob1,List &ob2)
{
    //insert the elements of first linked list in the hash table
    Node *temp=ob1.head;
    while(temp!=NULL)
    {
    	hashInsert(temp->data);
        temp=temp->next;
    }

    //now insert only those elements of second list which are already not in the hash table
    temp=ob2.head;
	 cout<<"Intersection:"<<endl;
    while(temp!=NULL)
    {
    	if(search(temp->data))
    		cout<<(temp->data)<<" ";
		temp=temp->next;
    }

}

//for displaying the linked list
void List::display()
{
    cout<<"List Contents:"<<endl;
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	List ob1;
	List ob2;
	//create first linked list
	for (int i = 0; i < 6; ++i)
	{
		ob1.push(&ob1.head,i);
	}
	ob1.display();

	//create first linked list
	for (int i = 3; i < 9; ++i)
	{
		ob2.push(&ob2.head,i);
	}
	ob2.display();
	ob2.intersection(ob1,ob2);
	ob2.Union(ob1,ob2);

	return 0;
}
