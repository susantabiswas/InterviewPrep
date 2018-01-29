//evaluate postfix expression
/*
	start scanning:
		if the char is operand :
			push into the stack
		else if it is operator:
			pop operands from the stack ,
			apply the operator to them and push the result
	pop the stack element
*/
#include<iostream>
#include<cmath>
#include<stack>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;

int evaluatePostfix(string exp){
	string::iterator it;
	stack<int> s;
	int op1;
	int op2 ;
	int ans = 0;

	//std::string::size_type sz;
	for(it = exp.begin(); it!= end(exp); it++){

		if(isdigit(*it)){
			s.push(*it - 48);
		}
		else{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();

			switch(*it){
				case '+':ans = op1 + op2;
						break;
				case '-':ans = op2 - op1;
						break;
				case '*':ans = op1 * op2;
						break;
				case '/':ans = op2/op1;
						break;
				case '^':ans = pow(op2,op1);
						break;
			}
			s.push(ans);
		}
	}
	ans = s.top();
	s.pop();
	return ans;
}

main(){
	string exp = "231*+9-";
	cout<<evaluatePostfix(exp);

}
