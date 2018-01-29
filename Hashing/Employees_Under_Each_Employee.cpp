//find the No. of keys associated with a particular value.
/*e.g:
	{ "A", "C" },
	{ "B", "C" },
	{ "C", "F" },
	{ "D", "E" },
	{ "E", "F" },
	{ "F", "F" }

	A - 0
	B - 0
	C - 2(A,B)
	D - 0
	E - 1(D)
*/
#include<iostream>
using namespace std;

struct Node
{
	Node *next;
	string key,value;
};

class Hash
{
private:
	//Hash table
	Node *h[10];
	//Reverse Hash Table
	Node *rh[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; ++i)
			h[i]=NULL;
		for (int i = 0; i < 10; ++i)
			rh[i]=NULL;
	}
	//for inserting the hash keys
	void insertHashVal(string,string);
	//for searching the no. of keys in the hash table of same name
	int search(string,Node**);
	//for mapping the index for a key value ,required in hash table
	int hashFunction(string);
	//for inserting the keys in front of the linked list
	void push(string,string,Node**);
	//finds the Itinerary from the key value pairs
	void findAssociatedKeys();

};

void Hash::push(string key,string value,Node **head)
{
	try{
		Node *node=new Node;
		node->key=key;
		node->value=value;
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
int Hash::hashFunction(string key)
{
	return key.length()%7;
}

//for insertion of keys
void Hash::insertHashVal(string key,string value)
{
	int in=hashFunction(key);
	push(key,value,&h[in]);

	in=hashFunction(value);
	push(value,key,&rh[in]);
}

//searches the key value pair
int Hash::search(string key,Node **head)
{
	int c=0;
	Node *temp=*head;

	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->key==key)
			{
				c=c+1+search(temp->value,&(*head));
			}
		temp=temp->next;
	}
	if(c==0)
		return 0;
	else
		return c;
}

//finds the No. of keys associated with a particular value.
void Hash::findAssociatedKeys()
{
	Node *temp=NULL;
	int in;

	//prints the key value pairs of hash table
	for (int i = 0; i < 10; ++i)
	{
		if(h[i]!=NULL)
		{
			temp=h[i];
			while(temp!=NULL)
			{
				in=hashFunction(temp->key);
				cout<<temp->key<<": "<<search(temp->key,&rh[in])<<endl;
				temp=temp->next;
			}
		}
	}
	cout<<endl;
}



int main()
{
	Hash ob;
	//create the hash table
	ob.insertHashVal("C","B");
	ob.insertHashVal("K","D");
	ob.insertHashVal("G","C");
	ob.insertHashVal("D","G");
	ob.insertHashVal("A","B");
	ob.insertHashVal("E","G");

	ob.findAssociatedKeys();
	return 0;
}


