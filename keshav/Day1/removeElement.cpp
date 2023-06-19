#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
        int n  = nums.size();
        if(n==0){
            return 0;
        }
        int i=0, j = n-1;
        while(i<j){
            if(nums[i]!=val){
                i++;
            }
            else{
                while(i<j && nums[j]==val){
                    j--;
                }
                if(i>=j){
                    return i;
                }
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        return nums[i]==val?i:i+1;
    }