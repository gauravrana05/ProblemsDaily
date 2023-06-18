#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {        
        int n = nums.size();
        
        set<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for( int i = 0; i < n-2 ; i++ ){
            for(int j = i+1; j < n-1; j++){

                int st = j+1;
                int end = n-1;

                long long sum = (long long)target - (long long)(nums[i]+nums[j]);

                while(st < end){
                    int s = nums[st] + nums[end];
                    if(s == sum){
                        vector<int> v = {nums[i], nums[j], nums[st], nums[end]};
                        sort(v.begin(), v.end());
                        ans.insert(v);
                        st++;
                        end--;
                    }
                    else
                    if(s < sum){
                        st++;
                    }

                    else
                        end--;

                   
                }
            }
        }
       
       vector<vector<int> > ret;

       for (auto i: ans){
           ret.push_back(i);
       } 
        return ret;
    }
};