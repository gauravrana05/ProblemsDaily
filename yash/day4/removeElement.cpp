class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==val)continue;
            ans.push_back(nums[i]);
        }
        int beg=0;
        for(auto i: ans){nums[beg]=i;beg++;}
    return ans.size();
    }
};
