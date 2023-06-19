#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums[0] == 0){
            return 0;
        }
    vector<int> reach(nums.size());

    reach[0] = nums[0];
    for(int i = 1; i < nums.size(); i++ ){
        reach[i] = max(nums[i] + i , reach[i - 1] );
    }  
    int index = 0;
    int ans = 0;
    while(index < nums.size() - 1){
        index = reach[index];
        ans++;
    }
    return ans;
    }
};