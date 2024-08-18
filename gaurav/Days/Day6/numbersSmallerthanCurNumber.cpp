#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(nums[i] > nums[j])
                    ans[i]++;

            }
        }
        return ans;
    }
};