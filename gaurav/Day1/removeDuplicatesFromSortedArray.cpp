#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> s;
        for(int i=0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int st = 0;
         for( auto i: s){
            nums[st] = i;
            st++;
         }

        return s.size();
    }
};