//Given a list of outcomes between different teams .Outcome is either win or loss.
//Given Teams A and B .Find if there exists any sequence of teams A...B such that
//each team has beaten the team on its right i.e if we have say A,C,D,B then A has
//beaten C ,C has beaten D and D has beaten B.
//NOTE:the sequence should contain all the teams

/*
	We can model this as a graph problem.
	We make an edge from  u to v if u has beaten v
	Then we just need to check if we can reach B from A.
	We can use BFS as well as DFS
	Here we use DFS
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<unordered_map>
#include<memory>
using namespace std;

//for storing the info for match results between two teams
struct MatchResult{
	string winning, loosing;
};

//for building the graph
unordered_map<string, unordered_set<string> > buildGraph(
					const vector<MatchResult>& matches){

	//create a graph
	unordered_map< string , unordered_set<string> > g;
	//iterate over the data
	for( const MatchResult& match: matches){
		g[match.winning].emplace(match.loosing);
	}
	return g;
}

//for doing dfs and finding whether the reachibility is there or not
bool isReachable( string source, string& dest,
				unordered_map< string , unordered_set<string> >& g,
				unordered_map<string, bool> &visited){
	//when there is no edge from source return
	if(g.find(source) == g.end()){
		cout <<source<<endl;
		return false;
	}
	if(source == dest)
		return true;
	//mark the current node as visited
	visited[source] = true;

	//check for reachibility using adj. nodes of source
	for(const string& team: g.at(source)){
		if(!visited[team])
			if(isReachable(team, dest, g, visited))
				return true;
	}

	return false;
}

//driver function
bool canABeatB(string& a, string& b, vector<MatchResult>& matches){
	unordered_map<string, bool> visited;
	unordered_map<string, unordered_set<string> > g = buildGraph(matches);

	//make each node unvisited
	unordered_map<string, unordered_set<string> >::iterator it;
	for(it = g.begin(); it!=g.end(); it++){
				visited[it->first] = false;
	}
	return isReachable(a, b, g, visited);
}
int main(){
	vector<MatchResult> matches(5);
	matches[0] = {"A","C"};
	matches[1] = {"A","D"};
	matches[2] = {"C","D"};
	matches[3] = {"D","B"};
	matches[4] = {"B","C"};


	string a = "A",b = "B";
	cout << canABeatB(a, b, matches);
}
