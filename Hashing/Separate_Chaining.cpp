//Hashing using Separate Chaining
#include<iostream>
#include<string>
using namespace std;

struct Node
{

	Node *next;
	string data;
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
	void insertHashVal(string str);
	//for searching the keys in the hash table
	void search(string str);
	//for deleting the keys in the hash table
	void deleteKey(string str);
	//for mapping the index for a string value ,required in hash table
	int hashFunction(string);
	//for inserting the keys in front of the linked list
	void push(int,string);
};

void Hash::push(int in,string str)
{
	try{
		Node *node=new Node;
		node->data=str;
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
int Hash::hashFunction(string str)
{
	return str.length()%7;
}

//for insertion of keys
void Hash::insertHashVal(string str)
{
	int in=hashFunction(str);
	push(in,str);
}

void Hash::search(string str)
{
	int in=hashFunction(str);
	Node *temp=h[in];
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->data==str)
			{
				cout<<"Found!\n";
				return;
			}
		temp=temp->next;
	}
	cout<<"Not found!!\n";
}

void Hash::deleteKey(string str)
{
		int in=hashFunction(str);
		Node *temp=h[in];
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->data==str)
			{
				temp->data="";
				return;
			}
		temp=temp->next;
	}
	cout<<"Key is absent!!\n";

}

int main()
{
	Hash ob;
	ob.insertHashVal("cheetah");
	ob.insertHashVal("lion");
	ob.insertHashVal("dog");
	ob.insertHashVal("cat");

	ob.search("dog");
	ob.deleteKey("dog");
	ob.search("dog");
	ob.search("cat");
	return 0;
}
