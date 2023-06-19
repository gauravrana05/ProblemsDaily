#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        for( int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                mp[nums[i]]++;
        }


        int i=1;
        cout<<mp.size();
        while(i) {
            cout<<i<<" ";
            if(mp.find(i) == mp.end()){
                return i;
            }
            i++;
        }

    return -1;
    }
};
