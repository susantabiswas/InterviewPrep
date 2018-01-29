//Given 'n' .Print all the binary numebers from 1 to 'n' using queue
#include<iostream>
#include<queue>
using namespace std;

void printBinaryNums(int n ){
	queue<string> q;
	q.push("1");
	string ini = "";
	int i = 0;
	while(i <n && !q.empty()){
		//save the starting part,the next two nums are obtained by appending 0 and 1 resp
		ini = q.front();
		q.pop();
		cout<<ini<<endl;

		q.push(ini + "0");
		q.push(ini + "1");
		i += 1;
	}
}

main(){
	int n = 10;
	printBinaryNums(n);
}
