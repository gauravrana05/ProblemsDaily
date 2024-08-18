class Solution {
public:
    
    int solve(int n,vector<int> &dp){
        if(dp[n] != 0)
            return dp[n];
        
        dp[n] = solve(n-1, dp) + solve(n-2 , dp);
        return dp[n];
        
    }

    int climbStairs(int n) {
            vector<int> dp(n + 1);
            dp[0] = 1;
            dp[1] = 1;
            return solve(n, dp);

    }
};