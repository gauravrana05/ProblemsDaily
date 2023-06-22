#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = INT_MIN ;

        int i = 0;
        while(i < nums.size()){
            curSum += nums[i];
            
            if(curSum > maxSum){
                maxSum = curSum;
            }
            if(curSum < 0){
                curSum = 0;
            }
            
            i++;
        }
        return maxSum;
    }
};