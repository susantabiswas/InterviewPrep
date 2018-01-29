//Multiply two numbers using arrays
#include<iostream>
#include<vector>
#include<algorithm>
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
	int carry =0,dcarry = 0,digit = 0;
	int index = 0;
	int ans;

	vector<int> C(n+m,0);	//for storing the result
	for(int i = m-1, k =0 ;i >=0 ,k<m; i--,k++){
		index = 0;
		dcarry = carry = 0;

		for(int j = n-1;j>=0; j--){
			digit = carry + A[j]*B[i];
			carry = digit/10;
			digit = digit%10;
         ans = digit + C[index +k] +dcarry;
			dcarry = ans / 10;
			ans = ans%10;
			C[index + k] = ans;
			index ++;
		}
		carry = carry + dcarry;
		//cout<<endl;
		//digit = dcarry +carry;
		if(carry){
			C [k +index] = carry;
		}

	}

	reverse(C.begin(),C.end());
	return C;
}

main(){
	vector<int> A = {9,8,7};
	vector<int> B = {1,2,3};
	vector<int> C = multiplyNum(A,B);

	disp(C);
}
