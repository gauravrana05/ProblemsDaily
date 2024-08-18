#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();

        int i = n-1;
            
            while(i > 0 && nums[i] <= nums[i-1]){
                i--;
            }

            if( i == 0 ){
                reverse(nums.begin(), nums.end());
                return;
            }

            int j = n-1; 
            i--;
            while( j > i){
                if( nums[i] >= nums[j]){
                    j--;
                }
                else{
                   break;
                }
            }
            int temp = nums[j];
            nums[j]=nums[i];
            nums[i]= temp;

            int st = i+1;
            int end = n-1;
            while(st < end){

                int temp = nums[end];
                nums[end]= nums[st];
                nums[st]=temp;

                st++;
                end--;

            }



        }
};