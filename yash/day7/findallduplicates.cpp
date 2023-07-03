#include<iostream>
using namespace std;
int main(){
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int arr[100000]={0};
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
    
        for(int i=1;i<100000;i++){
            if(arr[i]!=0){
                if(arr[i]==2){ans.push_back(i);}
            }
        }
    return ans;
    }

};
}
