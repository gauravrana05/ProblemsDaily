class Solution {
public:

    int solve(int n, vector<int> cost, vector<int> &dp){
        if(dp[n] != -1) 
            return dp[n];
        
        int prev = solve(n-1, cost, dp); 
        int prev1 = solve(n-2, cost, dp);

        dp[n] = cost[n] + min(prev, prev1); 
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size() + 1, -1);
        dp[0]= cost[0];
        dp[1]= cost[1];
       
         solve(cost.size() - 1, cost, dp);
         return min(dp[cost.size() - 1], dp[cost.size()- 2]);
    }
};