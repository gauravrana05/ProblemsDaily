#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int i = 0;

        for( int j = 0;j < n;j++){
            if(nums[j] == val){
                continue;
            }

            else{
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};