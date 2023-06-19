#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    sort(nums.begin(), nums.end());
    set<vector<int>> output;
    for (int i = 0; i < nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                output.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }
    vector<vector<int>> ans;
    for(auto vec: output){
        ans.push_back(vec);
    }
    return ans;
}

