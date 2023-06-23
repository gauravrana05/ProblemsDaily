#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int it = ans.size();
            ans.push_back(0);
            while(it > index[i]){
                ans[it]= ans[it-1];
                it--;
            }
            ans[index[i]] = nums[i];
        }
        return ans;
    }
};