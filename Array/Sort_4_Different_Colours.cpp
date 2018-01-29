//Given four different colours ,arrange them such that same colours exist together
/*
	for n value regions we use n pointers for the position
*/
#include<iostream>
#include<vector>
using namespace std;
typedef enum { c1,c2,c3,c4} colours;

//for swapping
void swap(vector<colours> &arr,int i,int j){
	colours t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

//for displaying  the vector
void disp(vector<colours> &arr){
	for(int i = 0; i < arr.size(); i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//for placing the colours in their correct position
void placeColours(vector<colours> &arr){
	int c1p = 0;
	int c2p = 0;
	int c3p = arr.size()-1;
	int c4p = arr.size()-1;

	/*
                     c1p    c2p,c3p    c4p
		-------------|---------|-------|-------------
			c1            c2        c3        c4
	*/
	while(c2p < c3p){
		if( arr[c2p] == c1){
			swap(arr,c1p,c2p);
			++c1p;
			++c2p;
		}
		else if(arr[c2p] == c2){
			++c2p;
		}
		else if(arr[c2p] == c4){
			swap(arr,c2p,c4p);
			--c4p;
			--c3p;
		}
		else{
			swap(arr,c2p,--c3p);
		}
	}
}

main(){
	vector<colours> arr = {c1,c3,c2,c4,c4,c3,c2,c1};
	placeColours(arr);
	disp(arr);
}
