//reverse a given string
#include<iostream>
#include<stack>
using namespace std;

string revString(string str){
	stack<char> s;
	string::iterator it;
	string ans = "";
	for(it = begin(str);it!=end(str);it++){
		s.push(*it);
	}

	while(!s.empty()){
		ans += s.top();
		s.pop();
	}
	return ans;
}

main(){
	string str = "MyNameIsSeeker";
	cout<<revString(str);
}
