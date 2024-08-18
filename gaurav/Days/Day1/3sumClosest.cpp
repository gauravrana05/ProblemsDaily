#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for( int i = 0; i < nums.size()-1; i++){
               int j = i+1;
               int k = nums.size()-1;
               while( j < k ){ 
                
                int val = target - nums[i];
                int sum = nums[j] + nums[k];
                if(abs(target - (sum + nums[i])) < abs(target - ans) ){
                    ans = sum + nums[i];
                }
                
                if( sum < val ){
                    j++;
                }
                else if(sum > val){
                    k--;
                }
                else{
                    return target;
                }

               }

        }

        return ans;

    }
};  