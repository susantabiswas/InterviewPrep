//Special stack ADT with added features like:
//getMiddle():returns middle element
//deleteMiddle():as the name suggests
//All these in O(1)
/*
	see count of elements .If the count becomes odd 
		then move the middle pointer
	otherwise on pop if the count becomes even 
		then move the middle backwards
*/
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class SpecialStack{
public:
	Node* head;
	Node* middle;
	int c;

	SpecialStack(){
		head = middle = NULL;
		c = 0;
	}

	Node* createNode(int);
	void push(int data);
	void pop();
	int getMiddle();
	void deleteMiddle();
	void disp();
};

void SpecialStack::disp(){
	Node* t = head;
	while(t){
		cout<<t->data<<" " ;
		t = t->next;
	}
	cout<<endl;
}

Node* SpecialStack::createNode(int data){
	Node* node = new Node;
	node->next = node->prev = NULL;
	node->data = data;
	return node;
}

//insertion is done at the begining ,so the middle element gets
//one step farther than it should so we move the middle ptr
//backwards if the size becomes even
void SpecialStack::push(int data){
	Node* node = createNode(data);
	if(head == NULL){
		head = node;
		c = 1;
		middle = head;
	}
	else{
		node->next = head;
		head->prev = node;
		++c;
		head = node;

		//move the middle pointer only when the total count gets even
		if(c % 2 == 0){
			middle = middle->prev;
		}
	}
}


void SpecialStack::pop(){
	if(head == NULL){
		cout<<"Underflow\n";
		return;
	}
	else{
		Node* t = head;
		head = head->next;
		head->prev = NULL;
		--c;
		delete t;
		//update middle only when the count gets even
		if(c%2 == 0){
			middle = middle->next;
		}
	}
}

void SpecialStack::deleteMiddle(){
	if(c == 1){
		Node *t = head;
		head = middle = NULL;
		delete t;
	}
	else if(c>1){
		Node* t = middle;
		if(middle->prev){
			middle->prev->next = middle->next;
		}
		middle->next->prev = middle->prev;
		middle = middle->next;
		delete t;
	}
}

int SpecialStack::getMiddle(){
	return middle?middle->data:NULL;
}

main(){
	SpecialStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.disp();

	cout<<s.getMiddle()<<endl;
	s.deleteMiddle();
	s.disp();
	cout<<s.getMiddle()<<endl;
	s.disp();
	s.pop();
	s.disp();
	cout<<s.getMiddle()<<endl;
	s.disp();

	//s.disp();
}
