//given an array ,where some part of it is unsorted .Find the length of min
//range of elements sorting which will give us the sorted array
#include<iostream>
#include<vector>
using namespace std;

//finds the range of elements sorting which will make the array sorted
/*
	first find the candidate range:
		start from left and find the first element that is smaller than its previous
		mark it as 's'
		start from right and do the same kind of thing and store as 'e'
	check if the unsorted list is enough:
		find the min and max of the range
		look for the first element from left that is greater than the min,mark it s
		look for the first smaller element from right that is smaller than the max and
		amrk it 'e'
		Since if only sorting those elements could make the array sorted then there
		would be no elements greater than the min of the range and same goes for the max
*/
int sortUnsorted(vector<int> &arr){
	int start,endp;
	int i = 1;

	//first find the starting pos
	while(arr[i]>=arr[i-1] && i<arr.size())
		i++;
	start = i;

	//find the first from the right which will be endp pos
	i= arr.size()-2;
	while(arr[i]<=arr[i+1] && i>=0)
		i--;
	endp = i;

	//check the candidate range
	int max = start,min = start;

	i = start;
	//find the max and min element
	while(i<=endp){
		if(arr[i] > arr[max])
			max = i;
		if(arr[i] < arr[min])
			min = i;
		i++;
	}

	//check for some element greater than the min on the left side
	i = 0;
	while(i<start){
		if(arr[i] > arr[min]){
			start = i;
			break;
		}
		i++;
	}

	//check for some element smaller than the max on the right side
	i = arr.size() - 1;
	while(i > endp){
		if(arr[i] < arr[max]){
			endp = i;
			break;
		}
		i--;
	}
	cout<<endl<<start<<" "<<endp;
	return (endp - start + 1);
}

void disp(vector<int> arr){
	for(int i = 0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	vector<int> arr = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	disp(arr);
	cout<<endl<<sortUnsorted(arr);
	//disp(arr);
	return 0;
}
