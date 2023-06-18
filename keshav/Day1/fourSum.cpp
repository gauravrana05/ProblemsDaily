#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target) {
      set<vector<int>> v;
      sort(nums.begin(), nums.end());
      
      for(int i = 0; i < nums.size(); i++){
        if(i != 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size(); j++){
          if(j != i + 1 && nums[j] == nums[j - 1]) continue;
          
          int k = j + 1;
          int l = nums.size() - 1;
          
          while(k < l){
            long long int sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
            if(target - sum == 0){
              v.insert({nums[i], nums[j], nums[k], nums[l]});
              k++;
              while(k < l && nums[k] == nums[k - 1]) k++;
            }
            else if(sum < target) k++;
            else l--;
          }
          
        }
      }
      vector<vector<int>> ans;
          for(auto vec:v){
            ans.push_back(vec);
          }

          return ans;
    }
