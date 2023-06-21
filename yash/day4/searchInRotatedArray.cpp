#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> nums{4,5,6,7,0,1,2};
	int high = nums.size()-1;
	int low = 0,mid,target=0;
	while(low<=high){
		mid = (low+high)/2;
		if(nums[mid] == target){cout<<mid;return 0;}
		//If left half of the array is sorted.
		if(nums[low]<nums[mid])
		{
			//If the element exists in the left array.
			if(nums[low]<=target && nums[mid]>=target){
				high = mid-1;
			}
			else {low = mid+1;}


		}

		//If the right half of the array is sorted.
		if(nums[mid]<nums[high]){
			//If the element exists in the right half.
			if(nums[mid]<target && target<nums[high]){low=mid+1;}
			else {high = mid-1;}





		}

	}
	cout<<-1;return -1;




//but this is not working in leetcode so simply go for linear search

}
