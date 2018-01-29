//given two arrays ,check whether arr2 is a subset of arr1 or not
/*
	1.can be done using binary search also by sorting the arrays and looking for 
	  elements of arr2 in arr1,but it won't handle the case when the arr2 has duplicates
	2. using hash 
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
	scan each element and make a hash table keeping the frequency of each element
	of arr1 .Start scanning arr2 and for each element found in the hash table check
	if the count of that element is greater than equal to 1 or not,if no
	that means arr1 doens't conatin that duplicate

*/
bool isSubset(vector<int> arr1, vector<int> arr2){
	//create a hash table
	map<int, int> h;
	for(int i = 0; i<arr1.size(); i++){
		//insert each new element in the hash table
		if(h.find(arr1[i]) == h.end()){
			h[arr1[i]] = 1;
		}
		//if there is already an instance ,increment its count to signify there is 
		//a duplicate 
		else
			h[arr1[i]]++;
	}

	//now starting looking for elements of arr2 in arr1
	for (int i = 0; i < arr2.size(); ++i)
	{
		//when element is not available
		if(h.find(arr2[i]) == h.end())
			return false;
		//when the frequency of current element in arr1 is lesser than in arr2
		else if(h[arr2[i]] <= 0)
			return false;
		else
			h[arr2[i]]--;

	}
	return true;
}

main(){
	vector<int> arr1 = {11,  1, 13, 21, 3, 7};
	vector<int> arr2 = {11, 11, 3, 7, 1};
	cout<<isSubset(arr1,arr2);
}
