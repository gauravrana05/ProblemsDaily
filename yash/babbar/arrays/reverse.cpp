#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
vector<int> nums;
nums.push_back(1);
nums.push_back(2);
nums.push_back(3);
nums.push_back(4);
nums.push_back(5);
int n = nums.size();
//Logic: Swap the starting and ending elements of symmetry and keep moving forward

for(int i = 0; i<n/2;i++){
swap(nums[i],nums[n-i-1]);
}

for(auto i:nums){cout<<i<<" "<<endl;}

}
