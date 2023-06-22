class Solution {

    int solve(vector<int> &a, vector<vector<int>> &dp, int i, int j){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++){
            dp[i][j] = max(dp[i][j],solve(a,dp,i,k)+solve(a,dp,k+1,j)+a[i-1]*a[k]*a[j]);
        }
        return dp[i][j];
    }


public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> a(n+2);
        a[0]=1;
        for(int i=0;i<n;i++) a[i+1] = nums[i];
        a[n+1]=1;
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(a,dp,1,n+1);
    }
};