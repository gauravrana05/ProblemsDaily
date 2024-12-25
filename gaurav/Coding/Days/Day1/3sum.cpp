#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     set< vector<int > > ans;
     
     sort(nums.begin(), nums.end());

     for( int i = 0; i < nums.size()-1; i++){
            int j = i+1;
               int k = nums.size()-1;
                    while(j < k){
                    if(nums[i] + nums[j] + nums[k] == 0){
                            vector<int> d = {nums[i], nums[j], nums[k]};
                            sort(d.begin(), d.end());
                            ans.insert(d);     
                            j++;
                            k--;
                   }
                   else if(nums[i] + nums[j] < -1 * nums[k]){
                       j++;
                   }
                   else {
                       k--;
                   }
                   }

        }     
    vector<vector<int> > ret;

    for(auto i: ans){
        ret.push_back(i);
    }
    return ret;
    }
};