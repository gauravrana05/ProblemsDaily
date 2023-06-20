class Solution {
public:

     void solve(vector<int> &a, set<vector<int>> &ans, int n,int cur){
        if(cur==n){
            ans.insert(a);
            return ;
        }
        solve(a,ans,n,cur+1);
        for(int i=cur+1;i<n;i++){
            swap(a[cur],a[i]);
            solve(a,ans,n,cur+1);
            swap(a[cur],a[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums,ans,nums.size(),0);
        vector<vector<int>> sol;
        for(auto v: ans){
            sol.push_back(v);
        }
        return sol;
    }
};