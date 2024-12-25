#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int itr = 0;
        for(auto i : nums)
            ans[itr++] = nums[i];
        return ans;
    }
};