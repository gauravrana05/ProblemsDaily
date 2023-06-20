class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end()||*it!=target){
            return {-1,-1};
        }
        int start = it-nums.begin();
        it = upper_bound(nums.begin(),nums.end(),target);
        int end = it-nums.begin()-1;
        return {start,end};
    }
};