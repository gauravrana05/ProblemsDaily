class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n,vector<bool>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    pal[i][j]=1;
                    continue;
                }
                pal[i][j] = s[i]==s[j] && !(i+1<=j-1 && !pal[i+1][j-1]);
            }
        }
        int dp[n];
        
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i]=0;
                continue;
            }
            int ans=dp[i-1]+1;
            for(int j=i;j>=0;j--){
                if(pal[j][i]){
                    if(j!=0){
                        ans=min(ans,dp[j-1]+1);
                    }
                    else{
                        ans=0;
                    }
                }
            }
            dp[i]=ans;
        }
        return dp[n-1];
    }
};