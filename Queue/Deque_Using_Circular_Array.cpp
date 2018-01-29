//Circular linked list using Array
#include<iostream>
#include<vector>
using namespace std;

struct CLL{
	vector<int> arr;
	int rear = -1;
	int beg = -1;
	int n = 0;
	CLL(int n){
		arr.resize(n);
		this->n = n;
	}
};

bool isFull(CLL* head){
	if( head->beg == head->rear+1 ||
		head->beg == 0 && head->rear == head->n-1)
		return true;
	else
		return false;
}

bool isEmpty(CLL *head){
	if(head->beg == -1 )
		return true;
	else
		return false;
}

//for displaying the elements
void disp(CLL *head){
	for(int i = 0; i<head->n; i++)
		cout<<head->arr[i]<<" ";
	cout<<endl;
}

//for insertion in End
void insertEnd(CLL *head,int data){
	cout<<endl<<"*********************PUSH******************\n";
	cout<<"Before data:"<<data<<" beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	if(isFull(head))
		return;
	if(head->beg == -1)
		head->beg =head->rear = 0;
	else if(head->rear == head->n - 1)
		head->rear = 0;
	else
		head->rear ++;
	head->arr[head->rear] = data;
	cout<<"After data:"<<data<<" beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	disp(head);

}

//insertion at Begining
void insertBegin(CLL *head,int data){
	cout<<endl<<"*********************PUSH******************\n";
	cout<<"Before data:"<<data<<" beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	if(isFull(head))
		return;
	if(head->beg == -1)
		head->beg =head->rear = 0;
	//update the writable index for front position
	else if(head->beg == 0)
		head->beg = head->n -1;
	else
		head->beg --;

	//push the element
	head->arr[head->beg] = data;
	cout<<"After data:"<<data<<" beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	disp(head);
}

//for deletion in begining
void delBegin(CLL *head){
	cout<<endl<<"*********************POP******************\n";
	cout<<"Before beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	if(isEmpty(head))
		return;

	if(head->beg == head->rear)
		head->beg =head->rear = -1;
	else if(head->beg == head->n -1)
		head->beg = 0;
	else
		head->beg++;
	cout<<"After beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	disp(head);
}

//deleteion at end
void deleteEnd(CLL *head){
	cout<<endl<<"*********************POP******************\n";
	cout<<"Before beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	if(isEmpty(head))
		return;

	if(head->beg == head->rear)
		head->beg = head->rear = -1;
	else if(head->rear == 0)
		head->rear = head->n -1 ;
	else
		head->rear--;
	cout<<"After beg:"<<head->beg<<" rear:"<<head->rear<<endl;
	disp(head);
}


int main(){
	CLL *head = new CLL(5);
	insertEnd(head,1);
	insertEnd(head,2);
	insertEnd(head,3);
	delBegin(head);
	delBegin(head);
	//insertEnd(head,3);
	insertEnd(head,4);
	insertEnd(head,5);
	insertEnd(head,6);
	insertEnd(head,7);
	insertEnd(head,8);
	disp(head);
	cout<<" **beg:"<<head->beg<<" rear:"<<head->rear<<endl;

	delBegin(head);
	delBegin(head);
	delBegin(head);
	deleteEnd(head);deleteEnd(head);

	insertBegin(head,44);
	insertEnd(head,55);
	disp(head);


	return 0;
}
