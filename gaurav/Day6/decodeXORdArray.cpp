#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(auto i : encoded){
            int temp = i ^ first;
            ans.push_back(temp);
            first = temp;
        }
        return ans;
    }
};