//Given two vectors representing the start and finish time of activities.
//Find the maximum number of activities that can be performed by a person
//Only one activity can be done at a particular time
/*
	Sort the activities by their finishing time
	then select the activities one by one and check if its start time is greater
	than equal to the finishing time of previous activity or not
	if yes
		then include that activity
	else
		proceed for the next one
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//for binding a activity with its start and finish time
struct activity{
	int start;
	int finish;
};

//for sort function comparator
bool comp(activity a, activity b){
	return a.finish < b.finish;
}

//finds the max no. of activities that can be performed
void maxActivity( vector<activity> &act){
	//sort the activities
	sort(act.begin(), act.end(), comp);
	//for keeping track of previous activity's finishing time
	int prev = act[0].finish;
	//print the first activity as the first that can be done
	cout << 0<<"(" << act[0].start <<"," << act[0].finish<<") ";
	for (int i = 1; i < act.size(); ++i)
	{
		if(act[i].start >= prev){
			cout << i<<"(" << act[i].start <<"," << act[i].finish<<") ";
			prev = act[i].finish;
		}
	}
}

int main(){
	vector<int> start = {1, 3, 0, 5, 8, 5};
	vector<int> finish = {2, 4, 6, 7, 9, 9};

	//create the activity structure
	vector<activity> act(start.size());
	for (int i = 0; i < start.size(); ++i)
	{
		act[i].start = start[i];
		act[i].finish = finish[i];
	}
	maxActivity(act);
	cout<<endl;
	for(int i = 0; i<act.size(); i++)
		cout<<act[i].finish<<" ";
}
