//given  the starting and departure time for trains.Find the min no. of stations required
//for working of railway station
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//finds the min stations required
/*
	Sort the arrays.
	Now at any particular instance we can find the number of stations required
	by seeing the number of trains that have arrived but not yet left
	As soon as a train leaves a station the platform count reduces by 1 and
	when a train arrives the count increases by 1
	We count this count during the merge step for the two arrays.We do something
	like in merge function of merge sort

	if arrival time < dept. time
		++c;
	else
		--c;
	and keep track of the max platform count
*/
int minStations( vector<int> &arr, vector<int> &dep){
	int max_count = 0;
	//no. of trains
	int n = arr.size();

	//sort the arrays
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	int i = 0;
	int j = 0;
	int count = 0;
	while(i < n && j<n){
		//when a train arrives
		if(arr[i] < dep[j]){
			++count;
		     i++;
		}
		//when the train departs
		else{
			  j++;
			--count;
		}
		if(count > max_count)
			max_count = count;
	}
	return max_count;
}

int main(){
	vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minStations(arr, dep);
    return 0;
}
