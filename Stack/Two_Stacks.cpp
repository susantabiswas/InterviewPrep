//Implement a DS such that there are two stacks using a single array
//supported op:push1,push2,pop1,pop2
#include<iostream>
#include<vector>
using namespace std;

struct TwoStacks{
	vector<int> arr;
	int top1;
	int top2;
	int n;

	TwoStacks(int na){
		arr.resize(na);
		top1 = -1;
		top2 = na;
		n = na;
	}
};

void push1(TwoStacks &s,int data){
	//check for overflow
	if(s.top1 + 1 == s.top2 || s.top1>= s.n){
		//cout<<(s.top1 + 1 == s.top2 )<<"  "<< (s.top1>= s.arr.size())<<" "<< s.arr.size()<<" "<<s.top1;
		cout<<"Overflow\n";
		return;
	}
	else
		s.arr[++s.top1] = data;
}


void push2(TwoStacks &s,int data){
	//check for overflow
	if(s.top2 - 1 == s.top1 || s.top2<0){
		cout<<"Overflow\n";
		return;
	}
	else
		s.arr[--s.top2] = data;
}

void pop1(TwoStacks &s){
	if(s.top1 == -1)
		cout<<"Underflow\n";
	else{
		s.top1--;
	}
}

void pop2(TwoStacks &s){
	if(s.top2 == s.arr.size())
		cout<<"Underflow\n";
	else{
		s.top2++;
	}
}

void disp(TwoStacks &s){
	for (int i = 0; i <=s.top1; ++i)
	{
		cout<<s.arr[i]<<" ";
	}
	cout<<endl;
	for (int i = s.n-1; i >=s.top2; --i)
	{
		cout<<s.arr[i]<<" ";
	}
	cout<<endl;

}
main(){
	struct TwoStacks s(10);


	for (int i = 1; i < 3; ++i)
	{
		push1(s,i);
		push2(s,i+1);
	}

	disp(s);
}
