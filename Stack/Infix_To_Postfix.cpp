//Infix to postfix expression
/*
	if operator is alphanumeric then print
	else:
		if it is ( :
			then push
		else if ):
			 then pop till you get ( .and pop ( also
		else you get an operator:
			pop stack elements till the top has lower or equal priority than the current op
			(for left associativity ) [for right associativity pop only when the priority is greater]
	if stack is not empty ,pop elements and print them
*/
#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

int getPriority(char c){
	int priority = -1;
	switch(c){
				case '+':
				case '-':	priority = 1;
							break;
				case '*':
				case '/':	priority = 2;
							break;
				case '^':	priority = 3;
							break;
			}
	return priority;
}

string convertPostfix(string exp){
	stack<int> s;
	string ans = "";
	string::iterator it;

	for(it = exp.begin();it!=exp.end();it++){
		if(isalpha(*it))
			ans+= *it;
		else{
			if(*it == ')'){
				while(!s.empty() && s.top()!= '('){
					ans += s.top();
					s.pop();
				}
				//pop ( also
				s.pop();
			}
			else if(*it == '(')
					s.push(*it);
			else{
				if(!s.empty()){
					while(!s.empty() && getPriority(s.top())>=getPriority(*it)){
						ans += s.top();
						s.pop();
					}
				}
				s.push(*it);
			}
		}
	}
	while(!s.empty()){
		ans += s.top();
		s.pop();
	}
	return ans;
}

main(){
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	cout<<convertPostfix(exp);
}
