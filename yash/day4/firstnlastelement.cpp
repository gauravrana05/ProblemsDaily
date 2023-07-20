#include<iostream>
#include<vector>
using namespace std;
int main(){

	vector<int> nums{5,7,7,8,10};
	int low=0,high = 5,mid,loc=0,target=8;
	
	while(low<=high){

		mid = (nums[low]+nums[high])/2;
		if(nums[low]<target && nums[mid]>target){
			high = mid-1;
		}
		else if(nums[mid]<target && nums[high]>target){low = mid+1;}
		else loc = mid;
		cout<<"low: "<<low<<endl;
		cout<<"Mid: "<<mid<<endl;
		cout<<"high: "<<high<<endl;
	}

	cout<<loc;
}
