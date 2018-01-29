//given an array and integer 'k' .check whether there lie any duplicate
//for a given element till 'k' distance from it.
/*
	use sliding window ,use a hash table and keep count of elements in the current
	window and check .When moving to the next window ,erase the first element
	previous window
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

//checks whether there exist any duplicate element within k distance
//from each element
//returns true if there are any such duplicates
bool duplicatesWithinKDist(vector<int> arr, int k){
	//create a hash table
	map< int, int > h;
	int i = 0;

	//first check for the first k elements
	for(i = 0; i<k; i++){
		if(h.find(arr[i]) == h.end()){
			h[arr[i]] = 1;
		}
		else
			return true;
	}

	//now scan for the rest of the elements
	for(; i<arr.size(); i++){
		//remove the first element of previous window
		h.erase(arr[i-k]);

		//insert the current element of the current window
		if(h.find(arr[i]) == h.end()){
			h[arr[i]] = 1;
		}
		else
			return true;
	}
	return false;
}

main(){
	int k = 2;
	vector<int> arr = {10, 5, 3, 4, 3, 5, 5};
	cout<< duplicatesWithinKDist(arr, k);
}
