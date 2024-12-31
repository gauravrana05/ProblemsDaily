#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);

        int i = 1;
        leftSum[0] = 0;
        rightSum[n-1] = 0;
        while( i < n ){
            leftSum[i] = leftSum[i-1] + nums[i - 1];
            rightSum[n - i - 1] = rightSum[n - i] + nums[n - i];
            i++;
        }
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};