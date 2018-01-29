//given a list of activities with their deadlines .Now if an activity is done
//before its deadline then we get profit.Each activity takes 1 unit time.
//Find the sequence to complete the activities such that the profit is maximum
//Each job has an id , profit and deadline associated with it
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
   char id;      // Job Id
   int deadline;    // Deadline of job
   int profit;
};

//custom comparator function for sort for sorting in decreasing order
bool comp( Job a, Job b){
	return a.profit > b.profit;
}

//prints the job sequence
/*
	Sort the jobs in decreasing order of profit
	then we create a free slot vector for knowing which time slots are free
	and also a sequence vector for knowing the sequence of jobs to be executed

	for each job see if its deadline has passed or not and whether it has a free slot or
	not
*/
void printJobSequence( vector<Job> &arr ){
	int n = arr.size();
	//sort the jobs
	sort(arr.begin(), arr.end(), comp);
	//for storing the sequence in which jobs are to be executed
	vector<string> sequence(n,"-1");
	//for knowing which slots are free and which are not
	//init all slots are free
	vector<bool> free_slot(n,true);
	//for keeping count of time
	int c = 1;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i].deadline >=c){
			//find the appropriate slot for it
			for (int j = min(n, arr[i].deadline)-1; j>=0 ; --j)
			{
				if(free_slot[j] == true){
					sequence[j] = arr[i].id;
					free_slot[j] = false;
					break;
					++c;
				}
			}
		}
	}

	//print the sequence
	for (int i = 0; i < n; ++i)
	{
		if(sequence[i] != "-1")
			cout<<sequence[i]<<" ";
	}
}

int main(){
	vector<Job> arr = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};

    printJobSequence(arr);
}
