//given many routes in the following format:
//from place1 to place 2
//Find the itinerary i.e the complete route using the given data
#include<iostream>
#include<unordered_map>
using namespace std;

//prints the itinerary
/*
	we just need to find the starting location.Now the starting location
	can never be the destination i.e starting location can't be present in the
	value set of keys
	So we maek another hash map where the keys will be the values of current map
	Then we search for the starting location
*/
void findItinerary(unordered_map<string, string> route){
	unordered_map<string, string> reverseMap;
	unordered_map<string, string>:: iterator it;

	//make the reverse hash map
	for(it = route.begin(); it!=route.end(); it++){
		reverseMap[it->second] = it->first;
	}

	//now search for the starting location
	for(it = route.begin(); it!=route.end(); it++){
		if(reverseMap.find(it->first) == reverseMap.end())
			break;
	}

	//now print the path
	int i = 0;
	while(i < route.size()){
		cout<<it->first<<"-> "<<it->second<<"  , ";
		it = route.find(it->second);
		++i;
	}
}

main(){
	unordered_map<string, string> route;
    route["Chennai"] = "Bangalore";
    route["Bombay"] = "Delhi";
    route["Goa"] = "Chennai";
    route["Delhi"] = "Goa";

    findItinerary(route);
}
