//given an array which is almost sorted that means the elements
//can be off their correct position by 1 place that is element[i]
//can be at element[i-1] or element[i+1].Given a key find it in this array
#include<iostream>
#include<vector>
using namespace std;

//we use modified binary search in which along with the
//mid element ,check also the right and left adjacent elements
int search(std::vector<int> &arr, int l, int r, int key){

	int mid = l +(r-l)/2;
	while(l<=r){
		mid = l + (r-l)/2;
		if(arr[mid] == key)
			return mid;
		if(mid - 1 > l && arr[mid-1] == key)
			return mid-1;
		else if(mid + 1 < r && arr[mid+1] == key)
			return mid+1;
		else if(arr[mid] < key)
			l = mid + 2;
		else if(arr[mid] > key)
			r = mid - 2;
	}
	return -1;
}

int main(){
	vector<int> arr = {3, 2, 10, 4, 40};
	int key = 4;
	int pos = search(arr,0,arr.size(),key);
	if(pos != -1)
		cout<<pos<<endl;
	else
		cout<<"Couldn't find it !\n";
	return 0;
}
