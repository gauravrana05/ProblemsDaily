class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int mi = INT_MAX;
        for(int i =0;i<n;i++){
            if(prices[i]<mi){
                mi = prices[i];
            }
            ans = max(ans,prices[i]-mi);
        }
        return ans;
    }
};