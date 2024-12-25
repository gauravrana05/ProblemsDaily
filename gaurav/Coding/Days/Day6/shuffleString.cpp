#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int itr = 0;
        for(auto i : indices)
            ans[i] = s[itr++];
        return ans;
    }
};