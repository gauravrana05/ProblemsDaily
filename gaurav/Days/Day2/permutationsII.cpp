#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
void solve(int n, vector<bool> &pos, vector<int> temp,vector<int> nums, vector<vector<int> > &ans){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(i < n-1 && nums[i] == nums[i+1] && pos[i+1] == false){
                continue;
            }
           
            if(pos[i] == true)
                continue;
            temp.push_back(nums[i]);
                pos[i] = true;
                solve(n, pos, temp, nums, ans);
                pos[i] = false;
                temp.pop_back();

        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end()); 
        vector<vector<int> > ans;
        vector<bool> pos(nums.size(), false);
        vector<int> temp;
        solve(nums.size(), pos,temp, nums, ans);
        return ans;
    }
};