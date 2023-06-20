class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long int sum = 0;
        vector<int> ans(n,-1);
        if(n<2*k+1){
            return ans;
        }
        int j = 2*k;
        for(int i = 0;i<=j;i++){
            sum+=(long)nums[i];
        }
        for(int i=k;i<n-k;i++){
            ans[i] = sum/(2*k+1);
            sum-=nums[i-k];
            j++;
            if(j<n) sum+=(long)nums[j];
        }
        return ans;
    }
};