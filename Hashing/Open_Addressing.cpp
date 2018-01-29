//Hashing using Open addressing
//This program uses Quadratic Probing to lessen the clustering

#include<iostream>
#include<string>
using namespace std;

class Hash
{
private:
	//Hash table
	string h[11];
public:
	Hash()
	{
		for (int i = 0; i < 10; ++i)
			h[i]=" ";
	}
	//for inserting the hash keys
	void insertHashVal(string str);
	//for searching the keys in the hash table
	void search(string str);
	//for deleting the keys in the hash table
	void deleteKey(string str);
	//for mapping the index for a string value ,required in hash table
	int hashFunction(int,string);
};

//hash function
int Hash::hashFunction(int i,string str)
{
	return (str.length()+i*i)%11;
}

//for insertion of keys
void Hash::insertHashVal(string str)
{
	int in;
	/*if h[in] is empty then insert the key there or
	keep on looking for the next empty bucket.If there is no empty bucket in the Hash Table
	Then make a new table with more no. of elements*/
		for (int i = 0; i < sizeof(h)/sizeof(string); ++i)
		{
			in=hashFunction(i,str);
			if(h[in]==" ")
			{
				h[in]=str;
				return;
			}
		}
}

void Hash::search(string str)
{
	int in;
	//for finding the index in the hash table
	for (int i = 0; i < sizeof(h)/sizeof(string); ++i)
	{
		in=hashFunction(i,str);
		if(h[in]==str)
		{
			cout<<"Key Found!\n";
			return;
		}
	}
	cout<<"Key not Found!\n";
}

void Hash::deleteKey(string str)
{
	int in;
	//for finding the index in the hash table
	for (int i = 0; i < sizeof(h)/sizeof(string); ++i)
	{
		in=hashFunction(i,str);
		if(h[in]==str)
		{
			h[in]=" ";
			return;
		}
	}
	cout<<"Key not Found!\n";
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
