#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(auto n : nums){
            int i = abs(n);
            if(nums[i] < 0)
                return i;
            nums[i] = - nums[i];
        }

    return -1;
    }
};