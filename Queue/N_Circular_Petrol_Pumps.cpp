//given 'n' petrol pumps located on the circumference of a circle .
//given the petrol each of pumps have and the dist from that ptrol pump to the next one
//find the first starting point such that we cover the entire circle
/*
	Using queue we store each petrol pump index and traverse.At any point if the
	the total petrol becomes lesser than the remaining distance, then dequeue the index
	and mark the next front index as the starting index
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//returns the first starting index of the petrol pump
int findStartingIndex(vector<int> &pet,vector<int> &dist){
	if(pet.size() == 1)
		return 0;

	queue<int> q;
	int start = 0;
	int pos = 1;
	int t_pet = pet[start];
	int t_dist = dist[start];
	int n = pet.size();
	//q.push(pos);

	while(pos != start){
		q.push(pos);

		while(t_pet < t_dist){
			//cout<<"entered : t_pet"<<t_pet<<" t_dist:"<<t_dist<<" start:"<<start<<endl;
			t_pet -= pet[start];
			t_dist -= dist[start];
			start = q.front();
			q.pop();
		}

		t_pet += pet[pos];
		t_dist += dist[pos];
		pos = (pos + 1)%n;
	}

	if(t_dist <= t_pet)
		return start;
	else
		return -1;
}

main(){

	vector<int> pet = {6,3,7};
	vector<int> dist = {4,6,3};
	int start = findStartingIndex(pet,dist);
	cout<<start;
}
