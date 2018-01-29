//Time Optimised Solution .TC:O(n)
//Convert a DLL to BST using in place conversion
/*
Recursively find the left subtree and right subtree as the traversal goes on.
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev=NULL;
	Node *next=NULL;
};

class DoublyList
{
	public:
		//data member
		Node *head;

		//member methods
		DoublyList(){ head=NULL; }
		Node* create(int);
		void InsertBegin(int);
		void Display();
		void InsertEnd(int);
		void InsertAnyPosition(int,int);
		Node* convertToBST(Node**,int);
        void inOrder(Node*);

};

//creates the node for DLL
Node* DoublyList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->prev=NULL;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}

//For inserting the nodes in the end of DLL
void DoublyList:: InsertEnd(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=node;
			node->prev=temp;

		}
	}
}

//converts the DLL into BST
//n:Size of DLL
Node* DoublyList::convertToBST(Node **head,int n)
{
    //base case:When the root is NULL .'n' ==0 when we pass a leaf node that is why the size is 0.
	if(n<=0)
		return NULL;

	//create the left subtree recursively
	Node *left=convertToBST(head,n/2);

	Node *root=*head;

	//point the left pointer of root to the left subtree
	root->prev=left;

	//required for creating the right subtree
	(*head)=(*head)->next;

	//recursively create the right subtree
	root->next=convertToBST(head,n-n/2-1);

	//point the right pointer of root to the right subtree

	return root;

}

//For Displaying the DLL
void DoublyList::Display()        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;

}


//inorder traversal of BST
void DoublyList::inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->prev);
    cout<<root->data<<" ";
    inOrder(root->next);
}
int main()
{
	DoublyList dll;
	//DLL creation
	for (int i = 1; i < 8; ++i)
		dll.InsertEnd(i);

	dll.Display();

	Node *root=dll.convertToBST(&dll.head,7);
	//inorder traversal of BST
	cout<<"BST Traversal:\n";
	dll.inOrder(root);

	return 0;
}
