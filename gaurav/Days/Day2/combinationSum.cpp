#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:

    void solve(int v, vector<int> cand, int target, int sum,vector<int> &temp, vector<vector<int> > &ans){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(temp);
            return;
            }
        
        for(int i = v; i < cand.size(); i++){
            
            sum += cand[i];
            temp.push_back(cand[i]);
            solve(i,cand, target,sum, temp,ans );
            temp.pop_back();
            sum -= cand[i];

        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector< int> > ans;
            vector<int> temp;
            int sum = 0;
            int i=0;
            solve(i,candidates, target, sum, temp, ans);
            return ans;
    }
};