class Solution {
public:

    void solve(vector<int> &a, vector<vector<int>> &ans, int n,int cur){
        if(cur==n){
            ans.push_back(a);
            return ;
        }
        solve(a,ans,n,cur+1);
        for(int i=cur+1;i<n;i++){
            swap(a[cur],a[i]);
            solve(a,ans,n,cur+1);
            swap(a[cur],a[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,nums.size(),0);
        return ans;
    }
};