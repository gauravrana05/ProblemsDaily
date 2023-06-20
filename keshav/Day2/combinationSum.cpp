void fun(vector<int>& a,int t,int start,vector<int> &cur,vector<vector<int>> &ans,int n){
        if(start == n){
            if(t == 0){
                ans.push_back(cur);
            }
            return ;
        }
        if(a[start]<=t){
            cur.push_back(a[start]);
            fun(a,t-a[start],start,cur,ans,n);
            cur.pop_back();
        }
        fun(a,t,start+1,cur,ans,n);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        fun(candidates,target,0,cur,ans,candidates.size());
        return ans;
    }