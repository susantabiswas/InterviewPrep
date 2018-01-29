//Merge  two balanced BSTs into one BST with Tc:O(m+n),where m,n are sizes of the two balanced BSTs respectively.

/*Make the two BSTs into DLLs
  Then merge the two DLLs
  Make BST from the merged DLL
*/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
};


//creates the node for DLL
Node* create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}



//converts the DLL into BST
//n:Size of DLL
Node* convertToBST(Node *root,int n)
{
    //base case:When the root is NULL .'n' ==0 when we pass a leaf node that is why the size is 0.
	if(root==NULL || n<=0)
		return NULL;

	//find the mid element of the DLL
	else
	{
		int mid =n/2;
		Node *temp=root;

		//traverse till the middle element
		for (int i = 0; i < mid; ++i)
		{
			root=root->right;
		}
        //make the prev as left pointer and next as right pointer
        root->left=convertToBST(temp,mid);
        root->right=convertToBST(root->right,n-mid-1);

		return root;
	}
}

//For Displaying the DLL
void Display(Node *head)        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->right;
    }
    cout<<endl;

}

//inorder traversal of BST
void inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//converts a BST to a DLL
/*Do inorder traverasl and during the convert it into a BST*/
Node* BSTtoDLL(Node *root)
{
	static Node *pre=NULL;

	if(root==NULL)
		return NULL;

	BSTtoDLL(root->left);

    cout<<root->data<<endl;
	root->left=pre;
	//if(pre!=NULL)
//        pre->right=root;
    pre=root;

	BSTtoDLL(root->right);
	return root;
}

//Merges the two BST
Node* mergeBST(Node *root1,Node *root2)
{
	//convert the first BST into a DLL
	Node *h1=BSTtoDLL(root1);
	cout<<"DLL\n";
	Display(h1);
}

int main()
{
	 /* Create following tree as 1st balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    Node *root1  = create(100);
    root1->left  = create(50);
    root1->right = create(300);
    root1->left->left = create(20);
    root1->left->right = create(70);

    /* Create following tree as 2nd balanced BST
            80
           /  \
         40   120
    */
    Node *root2  = create(80);
    root2->left  = create(40);
    root2->right = create(120);

    Node *h=BSTtoDLL(root2);
    cout<<endl<<h->data<<endl;
    Display(h);
    //then merge the two BSTs
    //Node *root=mergeBST(root1,root2);
    //inorder traversal of the merged BST
    //inOrder(root);

	return 0;
}
