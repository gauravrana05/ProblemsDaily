class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0,j=0;
        for(j=0;j<nums.size();j++){
            if(nums[j]==1);
            else if(k){
                k--;
            }
            else{
                while(nums.size()>i && nums[i]) i++;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};