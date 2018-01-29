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
//for displaying the elements
void disp(CLL *head){
	for(int i = 0; i<head->n; i++)
		cout<<head->arr[i]<<" ";
	cout<<endl;
}
//for insertion in begining
void insertEnd(CLL *head,int data){
	 //first element
	if(head->beg == -1 && head->rear == -1){
		head->beg = head->rear = 0;
		head->arr[head->rear % head->n] = data;
		//cout<<"1";
	}
	else if((head->rear + 1)%head->n == head->beg){
		cout<<"Overflow !"<<endl;
		//cout<<"2";
		return;
	}

	else{
			//cout<<"3";
		head->rear = (head->rear + 1) % head->n;
		head->arr[head->rear] = data;

	}

}



//for deletion in begining
void delBegin(CLL *head){
	//condition for underflow
	if(head->rear ==-1 && head->beg == -1){
		cout<<"Underflow !\n";
		return;
	}
	else if(head->rear == head->beg){	//when only one element is there
		head->rear = head->beg = -1;
	}
	else{
		head->beg = (head->beg + 1)% head->n;
	}

}




int main(){
	CLL *head = new CLL(5);
	insertEnd(head,1);
	insertEnd(head,2);
	insertEnd(head,3);
	insertEnd(head,4);
	insertEnd(head,5);
	insertEnd(head,6);
	insertEnd(head,7);
	disp(head);
	delBegin(head);
	delBegin(head);
	delBegin(head);
	delBegin(head);delBegin(head);
	delBegin(head);
	delBegin(head);
	disp(head);


	return 0;
}
