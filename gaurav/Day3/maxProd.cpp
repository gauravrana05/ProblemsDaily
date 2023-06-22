#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int prod=1;

        for(auto i : nums)
        {
          prod *= i;
          mx = max(prod,mx);
         
          if(prod==0)
                  prod=1;
        }
        prod = 1;
       
        for(int i=nums.size()-1;i >= 0; i--){
          
          prod *= nums[i];

          mx = max(prod, mx);
          if(prod==0)
             prod=1;
        }
        return mx;
    }
};