#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    int i = 1;
    int ans = 1;
    for(int j = 1;j<nums.size();j++){
        if(nums[j]!=nums[j-1]){
            nums[i]=nums[j];
            i++;
            ans++;
        }
    }
    return ans;
}
 