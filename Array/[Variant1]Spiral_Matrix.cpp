//Given a number 'd' .Generate an array such that the spiral traversal of it is
//such that <1,2,3......d^2>
#include<iostream>
#include<vector>
using namespace std;

template <class T>
void disp(T arr,int n){
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

//generates the matrix
/*
	Just do the spiral traversal
*/
vector< vector<int> > generateMatrix(int d){
	//allocate space for dXd matrix
	vector< vector<int> > arr(d,vector<int>(d));

	int k = 1;
	bool right = true,left =false, up =false, down = false;
	int rs = 0,re = d-1, cs = 0 ,ce = d-1;

	while(rs<= re && cs<=ce ){
		if(right){
			right = false;
			down = true;

			for(int i = cs ;i<= ce;i++)
				arr[rs][i]=k++;
			rs++;
		}
		else if(down){
			down = false;
			left = true;

			for(int i = rs ;i<= re;i++)
				arr[i][ce]=k++;
			ce--;
		}
		else if(left){
			left = false;
			up = true;

			for(int i = ce ;i>= cs;i--)
				arr[re][i]=k++;
			re--;
		}
		else if(up){
			up = false;
			right = true;

			for(int i = re ;i>=rs;i--)
				arr[i][cs]=k++;
			cs++;
		}
	}
	return arr;
}

int main(){
	int d =3;
	vector< vector<int> > D = generateMatrix(d);
	disp(D,d);
}
