class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int countZero = 0;
        long long int product = 1;
        int index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                countZero++;
                index = i;
            }
            else{
                product*=nums[i];
            }
        }
        if(countZero>1){
            return ans;
        }
        if(countZero == 1){
            ans[index] = product;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=product/nums[i];
        }
        return ans;
    }
};