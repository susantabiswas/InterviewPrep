//print binary numbers upto 'n'
/*  use a string queue,then initially insert '1' .
	then take the front i.e '1' and append '0' and push and append '1' and push .
	this makes the next binary numbers
*/
#include<iostream>
#include<queue>
using namespace std;

//prints the binary numbers
void printBianry(int n)
{
	//make a string queue
	queue<string> que;

	string s;

	que.push("1");
	while(n--)
	{
		s=que.front();
		que.pop();
		cout<<s<<endl;
		que.push(s+"0");
		que.push(s+"1");
	}
}

int main()
{
	printBianry(10);
	return 0;
}
