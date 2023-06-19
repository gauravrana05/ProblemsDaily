#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define debug1(x) cout<<#x<<' '<<x<<endl;
#define debug2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;

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
            if( i != v && cand[i] == cand[i-1] )
            continue;
            sum += cand[i];
            temp.push_back(cand[i]);
            // debug2(sum,cand[i]);
            solve(i+1,cand, target,sum, temp,ans );
            // debug2(temp.size(),temp.back());
            temp.pop_back();
            
            sum -= cand[i];

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector< int> > ans;
            vector<int> temp;
            int sum = 0;
            int i=0;
            sort(candidates.begin(), candidates.end());
            solve(i,candidates, target, sum, temp, ans);
            
            return ans;
    }
};
