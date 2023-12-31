#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        if(nums[start]==target){
                return start;
        }
        if(nums[end]==target){
            return end;
        }
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[start]){
                if(nums[start]<=target && nums[mid]>=target){
                    end = mid -1;
                }
                else{
                    start = mid+1;
                }
            }   
            else{
                if(nums[mid]<target && nums[end]>target){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            } 
        } 
        return -1;
    }
};