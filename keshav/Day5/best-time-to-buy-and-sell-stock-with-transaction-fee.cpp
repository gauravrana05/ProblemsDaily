class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        int n = price.size();
        int sell = 0, buy = -price[0];
        for(int i=1;i<n;i++){
            int temp = sell;
            sell = max(sell,buy+price[i]-fee);
            buy = max(buy,temp-price[i]);
        }
        return sell;
    }
};