//Multiply two numbers using arrays
//EPI solution
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//for displaying array elements
template <class T>
void disp(T c){
	for (int i = 0; i < c.size(); ++i)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
}

//for multiplying the numbers
vector<int> multiplyNum(vector<int> A,vector<int> B){
	int n = A.size();
	int m = B.size();

	//for knowing the sign
	int sign = A.front() < 0 ^ B.front() < 0 ? -1:1;
	//if there are neg nums
	A.front() = abs(A.front());
	B.front() = abs(B.front());

	vector<int> C(n+m,0);
	for(int i = A.size()-1; i>=0; i--)
		for(int j =B.size()-1; j>=0;j--){
			C[i+j+1] += A[i]*B[j];
			C[i+j] += C[i+j+1] / 10;
			C[i+j+1] %= 10;
		}

	//now the result might contain zereos
		//find_if_not returns the first position where predicate becomes false
		//so if there are 0s in front the functions passes ,but when the first num comes
		//it returns false
	C = vector<int>{find_if_not(begin(C),end(C),[](int x){
										 return !x;
										 }),end(C)};
   if(C.empty())
		return {0};
	C.front() = C.front()*sign;

	return C;
}

main(){
	vector<int> A = {9,8,7};
	vector<int> B = {1,2,3};
	vector<int> C = multiplyNum(A,B);

	disp(C);
}
