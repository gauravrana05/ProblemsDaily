#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = INT_MIN;
        for(auto i : candies)   
            mx = max(mx, i);
        int i = 0;
        vector<bool> ans(candies.size(),false);
        while(i < candies.size()){
            if( extraCandies + candies[i] >= mx)
                ans[i] = true;
            i++;
        }
        return ans;
    }
};