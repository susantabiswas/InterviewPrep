//given a linked list with node attributes :next pointer and random pointer:points to
//any random node in the list,Make a new linked list which is a copy of the original
//list,that is only the next pointer addresses will be in respect to the new list
/*
	Two approaches:
	1)using hashing:map each node with its duplicate
	2) Inserting each copy right after the original node
*/
#include<iostream>
#include<unordered_map>
using namespace std;

//linked list structure
//Node structure
struct Node{
	int data;
	Node *next;
	Node* random;

	Node(int n){
	data = n;
	next = NULL;
	random = NULL;
	}
};


//display function
void disp(Node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

//with hash
Node* cloneListHash(Node* head){
	unordered_map<Node*,Node*> h;
	Node* t = head;

	// make a copy for each node
	while(t){
		Node* node = new Node(t->data);
		node->next = node->random = NULL;
		h[t] = node;
		t = t->next;
	}
	t = head;
	//now modify the new copied nodes
	while(t){
		h[t]->next = h[t->next];
		h[t]->random = h[t->random];
		t = t->next;
	}
	return h[head];
}

Node* cloneListWithoutHash(Node* head){
	Node* t = head;
	Node* node;
	Node* nextptr;

	//make the nodes and insert them after the original nodes
	while(t){
      node = new Node(t->data);
      nextptr = t->next;
      node->next = t->next;
      t->next = node;
      t = nextptr;
	}

   Node* cloned_head = NULL;
   t = head;
   Node* duplicate = t->next;
   cloned_head = t->next;
   while(duplicate->next){
      duplicate->random = t->random->next;
      t->next = duplicate->next;
      t = duplicate->next;
      duplicate = duplicate->next->next;
   }
   duplicate->next = NULL;
   t->next = NULL;
   duplicate->random = t->random->next;


	return cloned_head;
}

int main(){
	Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;

	cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_head1 = cloneListHash(start);
    print(cloned_head1);
    cout << "\nCloned list : \n";
    Node *cloned_head2 = cloneListWithoutHash(start);
    print(cloned_head2);
}
