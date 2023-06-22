class Solution {
public:

    long long int calc(int val, vector<int> &a, vector<int> &b){
        long long int ans = 0;
        for(int i=0;i<a.size();i++){
            ans+=(long)b[i]*abs(val-a[i]);
        }
        return ans;
    }

    int minimum(vector<int> &a){
        int ans =INT_MAX;
        for(int i:a) ans = min(ans,i);
        return ans;
    }

    int maximum(vector<int> &a){
        int ans =INT_MIN;
        for(int i:a) ans = max(ans,i);
        return ans;
    }


    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = minimum(nums);
        int r = maximum(nums);
        long long int ans = INT_MAX;
    
        while(l<=r){
            int mid = (l+r)/2;
            long long int cost1 = calc(mid,nums,cost);
            long long int cost2 = calc(mid+1,nums,cost);
            ans = ans==INT_MAX ? min(cost1,cost2) : min({ans,cost1,cost2});
            if(cost1>cost2){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};