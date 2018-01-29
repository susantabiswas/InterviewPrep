//Find whether an array is subset of another array
/*This solution uses STL vector*/
#include<iostream>
#include<vector>
using namespace std;

struct Hash
{
	vector<int> l;
};
class Hashing
{
	private:
			Hash h[10];
	public:
		int hashFunction(int);
		void hashInsert(int);
		bool isSubset(vector<int>,vector<int>);
};

//hash function
int Hashing::hashFunction(int val)
{
	return val%11;
}

//for inserting the hash keys
void Hashing::hashInsert(int val)
{
	int in=hashFunction(val);
	h[in].l.push_back(val);
	cout<<"Insert>> in:"<<in<<" val:"<<val<<endl;
}

//check whether array 2 is a subset of first array or not
bool Hashing::isSubset(vector<int> arr1,vector<int> arr2)
{
	int in;
	//insert the elements of arr1 in the hash table
	for (int i = 0; i < arr1.size(); ++i)
	{
		hashInsert(arr1[i]);
	}

	int f=0;
	//check whether each element of arr2 exist in arr1 or not
	for(int i=0;i<arr2.size();i++)
	{
		f=0;
		in=hashFunction(arr2[i]);

		for(int j=0;j<h[in].l.size();j++)
		{
			if(h[in].l[j]==arr2[i])
			{
				f=1;
				break;
			}
		}
		if(f==0)
			return false;
	}
	return true;
}

int main()
{
	Hashing ob;
  vector<int> arr1 {11, 1, 13, 21, 3, 7};
  vector<int> arr2{11, 3, 7, 1};

	if(ob.isSubset(arr1,arr2))
			cout<<"Second array is a subset of first array\n";
	else
		cout<<"Second array is not a subset of first array\n";

	return 0;
}
