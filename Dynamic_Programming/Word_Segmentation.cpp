//word segmentation
//Given a dict containing various words and a given input string
//We have to see whether the given string can be broken down into space seperated words
//such that the words matches those from the dictionary
//eg : dict = { i,do, this, code}
//str: ido
//then: i do ==>matches words from the dictionary
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;


//check if the string is in the dict or not
bool isContained(string str, vector<string> &dict){
	for (int i = 0; i < dict.size(); ++i)
	{
		if(str == dict[i])
			return true;
	}
	return false;
}

/*
	For each prefix we search whether the word is there in the dictionary or not
	if it is there then recurse for the ramaining part of the string or just increase
	the prefix length by 1
*/
//Tc:O(2^n)
bool wordSegmentationPoss( string str, vector<string> &dict){
	int n = str.size();

	//base case
	if(n == 0)
		return true;
	//now check for the possible prefix that can be found inside the dict
	for(int i = 1; i<=n; i++){
		if( isContained(str.substr(0,i), dict) && 
		    wordSegmentationPoss( str.substr(i,n-i), dict) )
			return true;
	}
	return false;
}

//using DP:Memoization
//Tc:O(n^3):substr takes O(n) and for f(substr(0,i)) + f(substr(i,n-i)) takes O(n^2)
//as all the possible combinations are tried and in each try the entire string is run
bool wordSegmentationPossMem( string str, vector<string> &dict, 
							  unordered_map< string,int > lookup){
	int n = str.size();

	//base case
	if(n == 0)
		return true;
	if(lookup.find(str) != lookup.end())
		return lookup[str];

	//now check for the possible prefix that can be found inside the dict
	for(int i = 1; i<=n; i++){
		if( isContained(str.substr(0,i), dict) && wordSegmentationPossMem( str.substr(i,n-i), dict, lookup) )
			return lookup[str] = 1;
	}
	return lookup[str] = 0;
}

main(){
	vector<string> dict = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    string str = "samsungandmangok";
    cout << wordSegmentationPoss(str,dict);

    //for dp
    unordered_map< string,int > lookup;
    cout << endl << wordSegmentationPossMem(str,dict,lookup);
}
