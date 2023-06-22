#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long int> sum(n, 0);
        vector<int> ans(n, -1);
        sum[0] = nums[0];
        for(auto i = 1; i< n; i++){
            sum[i] =  sum[i - 1] + nums[i];
        }
        if(n < 2 * k + 1){
            return ans;
        }


        for( int i = k; i < nums.size() - k ; i++){ 

            ans[i] = (sum[i + k] - sum[i - k] + nums[i - k]) / (2 * k + 1);

            // cout<<sum[i-k]<<" "<<sum[i + k]<<" ans: "<<ans[i]<<endl;
        }
        return ans;
    }
};