//remove duplicates from an array
#include<iostream>
#include<vector>
using namespace std;

template <class T>
void disp(T arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//for removing duplicates
/*
	We write the elements when it is not equal to its previous one.
	Initially the vacant and moving position were at the same position and whenever 
	a different ele was found it was written to the vacant position

	vacant gives us the position where the next unique element is going to get stored,
	incase the current element is not unique the moving position moves further but 
	the vacant stays there only.
*/
vector<int> removeDuplicates(vector<int> &arr){
	//vacant gives us the writing position
	int vacant = 1;
	int i =1;

	for(int i =1; i<arr.size();i++){
		if(arr[vacant-1] != arr[i])
			arr[vacant++] = arr[i];
	}

	return vector<int>{begin(arr),begin(arr) + (vacant)};
}

main(){
	vector<int> arr ={ 1,2,2,3,3,3,7,7,8};
	vector<int> res = removeDuplicates(arr);
	disp(res);
}
