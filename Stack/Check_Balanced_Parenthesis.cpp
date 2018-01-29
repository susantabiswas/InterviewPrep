//check for balanced parenthesis
/*
	while scanning:
		if it is left something:
			then push
		if is right:
			if the stack is empty then return false
			else
				if the stack top is not matching with current right something
					then return false
	if stack is non empty
		return false
	return true
*/
#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str){
	stack<char> s;
	string::iterator it;

	for(it = begin(str); it!=end(str); it++){
		if(*it == '(' || *it=='[' || *it=='{')
			s.push(*it);
		else
			switch(*it){
				case '}':if(!s.empty()){
								if(s.top()!='{')
									return false;
								else{
									s.pop();
									break;
								}
						}
						else
							return false;
				case ']':if(!s.empty()){
								 if(s.top()!='[')
									return false;
								else{
										s.pop();
										break;
									}
							}
							else
								return false;
				case ')':if(!s.empty()){
								if(s.top()!='(')
									return false;
								else{
										s.pop();
										break;
									}
							}
							else
								return false;
			}
	}
	if(!s.empty())
		return false;
	return true;
}

main(){
	string exp = "}";
	cout<<isBalanced(exp);
}
