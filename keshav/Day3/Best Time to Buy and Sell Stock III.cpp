class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy=prices[0];
        int n=prices.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        for(int i=1;i<n;i++){
            minBuy=min(minBuy,prices[i]);
            dp1[i]=max(dp1[i-1],prices[i]-minBuy);
        }
        int maxSell=prices[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            maxSell = max(maxSell,prices[i]);
            dp2[i]=max(dp2[i+1],maxSell-prices[i]);
            ans=max(ans,dp1[i]+dp2[i]);
        }
        return ans;
    }
};