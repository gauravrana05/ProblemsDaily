#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealth(accounts.size());
        int mx = INT_MIN;
        
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 0; j< accounts[i].size(); j++){
                wealth[i] +=accounts[i][j];
            }
        }

        for(auto i: wealth)
            mx = max(mx, i);
        return mx;
    }
};