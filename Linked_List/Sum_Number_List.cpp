//To get a List which represents the sum of two numbers represented by given linked lists
//The numbers are already given in the linked list
/*Given Numbers in the list are in the reverse order ,
but the sum is represented in the correct order
Input:
  First List: 9->9->9  // represents number 999
  Second List: 2->2->3->2 //  represents number 2322
Output
  sum List: 3->3->2->1  // represents number 3321
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class List
{
public:
	Node *head;				//head for the list

	List() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void sum(Node*,Node*);
	void Display();
	
};


Node* List::create(int localData)			//for creating a node
{

	try {

		Node *node = new Node;
		if (node == NULL)
		{
			cout << "Allocation failure\n";
		}

		node->data = localData;
		node->next = NULL;
		return node;
	}
	catch (bad_alloc xa)
	{
		cout << "Allocation failure\n";
		return NULL;
	}

}


void List::InsertBegin(int dataItem)			//for inserting the node in the of Beginning list
{
	Node *node = create(dataItem);
	if (node!=NULL)
	{
		if (head == NULL)
		{
			head = node;
			node->next = NULL;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	else
	{
		cout << "Can't create node\n";
	}

}

//Makes a list which represents the sum of the two lists
void List::sum(Node *temp1,Node *temp2)
{
	//when both the lists are empty
	if(temp1==NULL && temp2==NULL)
		return ;

	//when list1 is empty,sum is List2
	if(temp1==NULL && temp2!=NULL)
	{
		//create a sum list
		while(temp2!=NULL)
		{
			InsertBegin(temp2->data);
			temp2=temp2->next;
		}
		return;
	}

	//when list2 is empty,sum is List1
	if(temp2==NULL && temp1!=NULL)
	{
		//create a sum list
		while(temp1!=NULL)
		{
			InsertBegin(temp2->data);
			temp2=temp2->next;
		}
		return;
	}

	int sum=0;
	int carry=0;
	//add nodes from each list to the sum list
	while(temp1!=NULL && temp2!=NULL)
	{
		sum=temp1->data+temp2->data+carry;
		carry=0;
		if(sum>=10)
		{
			InsertBegin(sum%10);
			sum=sum/10;
			carry=sum%10;
		}

		//traverse further
		temp1=temp1->next;
		temp2=temp2->next;

	}

	//if both the lists gets empty
	if(temp1==NULL && temp2==NULL)
		{
			if(carry!=0)
				InsertBegin(carry);
			return;
		}
	//if either of the two lists gets empty

	//when list1 is empty and there are nodes left in list2
	if(temp1==NULL)
	{
		while(temp2!=NULL)
		{
			sum=temp2->data+carry;
			carry=0;
			if(sum>=10)
			{
				InsertBegin(sum%10);
				sum=sum/10;
				carry=sum%10;
			}
			//Insert the sum in new list
			InsertBegin(sum);

			//traverse further
			temp2=temp2->next;
		}
		if(carry!=0)
			InsertBegin(carry);
		return;
	}

	//when list1 is empty and there are nodes left in list2
	if(temp2==NULL)
	{
		while(temp1!=NULL)
		{
			sum=temp1->data+carry;
			carry=0;
			if(sum>=10)
			{
				InsertBegin(sum%10);
				sum=sum/10;
				carry=sum%10;
			}
			//Insert the sum in new list
			InsertBegin(sum);

			//traverse further
			temp1=temp1->next;
		}
		if(carry!=0)
			InsertBegin(carry);
		return;
	}
}

void List::Display()						//for displaying the list
{
	cout << "\nContents of List:\n";
	Node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	List list1,list2,list3;

	//list 1 : 9->9->9  ,number is 999
	list1.InsertBegin(9);
	list1.InsertBegin(9);
	list1.InsertBegin(9);

	list1.Display();

	//list 1 : 2->3->2->2,number is 2232
	list2.InsertBegin(2);
	list2.InsertBegin(3);
	list2.InsertBegin(2);
	list2.InsertBegin(2);

	list2.Display();
	list3.sum(list1.head,list2.head);

	//sum is represented in the correct order not in the reverse order
	list3.Display();
	return 0;
}
