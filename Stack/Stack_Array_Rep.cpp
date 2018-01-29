//stack using array
#include<iostream>
#include<vector>
using namespace std;

template <class T>
struct Stack{
	vector<T> arr;
	int top;
	int size = 0;
	Stack(int n){
		arr.resize(n,0);
		top = -1;
		size = n;
	}
};

template <class T>
bool isEmpty(Stack<T> &s){
	if(s.top == -1)
		return true;
	else
		return false;
}

template <class T>
bool isFull(Stack<T> &s){
	if(s.top >= s.size - 1)
		return true;
	else
		return false;
}

template <class T>
void push(Stack<T> &s,int data){
	if(isFull(s)){
		cout<<"Overflow"<<endl;
		return;
	}
	else{
		s.arr[++s.top] = data;
	}
}

template <class T>
void pop(Stack<T> &s){
	if(isEmpty(s))
		cout<<"Underflow \n";
	else
		s.top--;
}

template <class T>
void disp(Stack<T> &s){
	int n = s.top;
	for(int i = 0;i<=n;i++)
		cout<<s.arr[i]<<" ";
	cout<<endl;
}

main(){
	Stack<int> s(10);
	for(int i = 1;i<7;i++)
		push(s,i);
	disp(s);
}
