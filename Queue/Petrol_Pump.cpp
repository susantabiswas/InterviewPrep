//Given Petrol pumps with their petrol qty,and the distance to the next petrol pump.
//Find the starting point from where if the track starts all the petrol pumps can be travelled
#include<iostream>
using namespace std;

struct petrolPump
{	//qty of petrol
	int petrol;
	//distance to the next petrol pump
	int dist;
};

//finds the starting petrol pump such that from there all the petrol pumps can be travelled
int getStarting(petrolPump arr[],int n)
{
	int start=0;
	int end=1;

	//start with the first petrol pump
	int currPetrol=arr[start].petrol-arr[start].dist;

	//while we don't cover all the petrol pumps or while some petrol is still left
	while(end!=start || currPetrol>0)
	{
		//check if the current petrol has become less than zero
		//if true then the current starting point is not the desired starting point
		while(currPetrol<0)
		{
			currPetrol=currPetrol-arr[start].petrol+arr[start].dist;

			//change the starting point
			start=(start+1)%n;
            end=(end+1)%n;
			//if the current petrol still doesn't become positive and gets equal to the initial start i.e 0
			//then there is no way possible
			if(start==0)
				return -1;
		}
		currPetrol+=arr[end].petrol-arr[end].dist;
		end=(end+1)%n;
	}
    return start;
}

int main()
{
	petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int size = sizeof(arr)/sizeof(arr[0]);
    int start = getStarting(arr, size);

    if(start==-1)
        cout<<"Not possible\n";
    else
        cout<<start<<endl;

 	return 0;
}
