#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int st=0; 
        int end =nums.size()-1;

        int mid = (st + end) / 2;

        while( st <= end){
            
            if(target == nums[mid]){
                return mid;
            }

            if( nums[st] <= nums[mid]){
                if(target >= nums[st] && target < nums[mid]){
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }
            else{
                    if(target > nums[mid] && target <= nums[end]){
                        st = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }

            mid = (st + end) / 2;
        }

        return -1;
    }
};