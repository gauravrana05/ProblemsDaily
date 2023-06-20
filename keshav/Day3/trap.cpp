class Solution {
public:
    int trap(vector<int>& heights) {
        int leftMax = INT_MIN, rightMax = INT_MIN, l = 0 , r = heights.size() - 1;
        int ans = 0;
        while(l<r){
            leftMax = max(leftMax,heights[l]);
            rightMax = max(rightMax,heights[r]);
            if(heights[l]<heights[r]){
                ans+=max(0,min(leftMax,rightMax) - heights[l]);
                l++; 
            }
            else{
                ans+=max(0,min(leftMax,rightMax) - heights[r]);
                r--; 
            }
        }
        return ans;
    }
};