//Find whether an array is subset of another array
/*sort both the arrays and check if the second array lies in the first or not*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//finds whether the second is a subset or not
bool isSubset(vector<int> arr1,vector<int> arr2)
{
	//sort the two arrays
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());

	int i=0,j=0;
	//now traverse the vectors and check
	while(i<arr1.size() && j<arr2.size())
	{
		if(arr1[i]<arr2[j])
			++i;
		else if(arr1[i]==arr2[j])
		{
			++i;
			++j;
		}
		else
			return false;
	}
	//arr2 has been fully traversed so it is a subset
	if(j==arr2.size())
		return true;
	else
		return false;
}

int main()
{
 	vector<int> arr1 {11, 1, 13, 21, 3, 7};
  	vector<int> arr2{1, 3, 7, 11};

	if(isSubset(arr1,arr2))
			cout<<"Second array is a subset of first array\n";
	else
		cout<<"Second array is not a subset of first array\n";

	return 0;
}
