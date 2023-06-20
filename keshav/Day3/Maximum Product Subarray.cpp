class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // MY INITIAL APPROACH
        
        // int ans = nums[0],negProduct=1,curProduct=0,index=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         negProduct = 1;
        //         curProduct = 0;
        //         index = -1;
        //         ans = max(ans,0);
        //         continue;
        //     }
        //     if(curProduct==0) curProduct = 1;
        //     curProduct*=nums[i];
        //     if(negProduct==1 && curProduct<0 && i!=nums.size()-1){
        //         negProduct = curProduct;
        //         index = i;
        //     }
        //     ans = max({ans,curProduct});
        //     if(index!=-1 && index!=i){
        //         ans = max(ans,curProduct/negProduct);
        //     }
        // }
        // return ans;



        //ANOTHER GOOD APPROACH
        int ans = nums[0], curMax = nums[0], curMin = nums[0];

        for(int i=1;i<nums.size();i++){
            int m = max({ curMax* nums[i], nums[i], curMin * nums[i]});
            curMin = min({curMax * nums[i], nums[i], curMin * nums[i]});
            curMax = m;
            ans = max(ans,curMax);
        }
        return ans;

    }
};