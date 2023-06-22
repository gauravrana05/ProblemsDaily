#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int cZ = 0;
        for(auto i : nums){
               if( i != 0)
               prod *= i;
               else
               cZ++;
        }
        if (cZ > 1){
            vector<int> ans(nums.size(), 0);
            return ans;
        }

    vector<int> ans = nums;
    for( auto i = 0; i < nums.size(); i++ ){
        if(cZ == 1)
        if(ans[i] == 0)
            ans[i] = prod;
        else
            ans[i]= 0;
        else
            ans[i]= prod/ans[i];
    
    }
    return ans;
    }
    
};