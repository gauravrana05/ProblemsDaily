#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define debug1(x) cout<<#x<<' '<<x<<endl;
#define debug2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;

class Solution {
public:

    void findSt(vector<int> nums, int l, int r,int target, int &st){
            
            st = r;
            int mid = (l + r) / 2;
        while(l <= r){
            
            debug2(l, r);
            debug2(mid, nums[mid]);
            if( nums[mid] == target ){
                debug2(st,mid);
                st = mid;
                r = mid - 1 ;
            
            }
            else
                l = mid + 1;
                
                mid = (l + r) / 2;

    }

    }

    void findEnd(vector<int> nums, int le, int r,int target, int &end){
            end = le;
        while(le <= r){
            int mid= (le + r) / 2;
            debug2(le, r);
            if( nums[mid] == target ){
                end = mid;
                le = mid + 1;
            }
            else
                r = mid - 1 ;
        }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int st = -1;
        int end = -1;

        int l = 0; 
        int r = nums.size() - 1;

        while( l <= r ){

            debug2(l, r);

            int mid = (l + r) / 2;
            
            debug2(mid, nums[mid]);

                if (nums[mid] == target ){

                    findSt(nums, l, mid,target, st);
                    findEnd(nums, mid, r, target, end);

                    debug2(st, end);
                    break;
                }

                if(nums[mid] > target)
                    r = mid -1;
                else
                    l = mid + 1;

        }

        return {st, end};

    }
};