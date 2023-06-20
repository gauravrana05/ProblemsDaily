class Solution {
public:

    void fun(vector<int>& a,int t,int start,vector<int> &cur,set<vector<int>> &ans,int n){
        if(t == 0){
            ans.insert(cur);
        }
        if(start == n){
            return ;
        }
        if(a[start]<=t){
            cur.push_back(a[start]);
            fun(a,t-a[start],start+1,cur,ans,n);
            cur.pop_back();
        }
        while(start!=n-1 && a[start] == a[start+1]){
            start++;
        }
        fun(a,t,start+1,cur,ans,n);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set <vector<int>> ans;
        vector<int> cur;
        vector<vector<int>> sol;
        sort(candidates.begin(),candidates.end());
        fun(candidates,target,0,cur,ans,candidates.size());
        for(auto v:ans){
            sol.push_back(v);
        }
        return sol;
    }
};