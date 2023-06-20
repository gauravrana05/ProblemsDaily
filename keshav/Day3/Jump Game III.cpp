class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(!arr[start]) return true;
        int n = arr.size();
        vector<bool> vis(n,false);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            if(t+arr[t]<n&&!vis[t+arr[t]]){
                vis[t+arr[t]]=1;
                if(!arr[t+arr[t]]) return true;
                q.push(t+arr[t]);
            }
            if(t-arr[t]>=0&&!vis[t-arr[t]]){
                vis[t-arr[t]]=1;
                if(!arr[t-arr[t]]) return true;
                q.push(t-arr[t]);
            }
        }
        return false;
    }
};