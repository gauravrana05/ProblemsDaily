class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        queue<int> q;
        vector<bool> vis(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        int ans = -1;
        q.push(0);
        while(!q.empty()){
            ans++;
            int k=q.size();
            for(int i=0;i<k;i++){
                int t = q.front();
                q.pop();
                if(t<0||t>=n) continue;
                if(t==n-1){
                    return ans;
                }
                if(t-1>=0&&!vis[t-1]){
                    q.push(t-1);
                    vis[t-1]=1;
                }
                if(!vis[t+1]){
                    q.push(t+1);
                    vis[t+1]=1;
                }
                vector<int> c = m[arr[t]];
                for(int j=c.size()-1;j>=0;j--){
                    if(!vis[c[j]]){
                        q.push(c[j]);
                        vis[c[j]]=1;
                    }
                }
                m[arr[t]] = {};
            }
        }
        return 0;
    }
};