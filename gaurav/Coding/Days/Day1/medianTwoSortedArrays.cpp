#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merge;
        int st1 = 0, e1 = nums1.size();
        int st2 = 0, e2 = nums2.size();
// st1 and e1 are start and end for 1st sorted array
// st2 and e2 are start and end for the 2nd sorted array
//merging two sorted arrays such that the resulting merge
//array also remains sorted
        while(st1 < e1 && st2 < e2){

                if(nums1[st1] < nums2[st2]){
                    merge.push_back(nums1[st1]);
                    st1++;
                }
                else if(nums1[st1] >= nums2[st2])
                {
                    merge.push_back(nums2[st2]);
                    st2++;
                }

        }

        while(st1 < e1){
            merge.push_back(nums1[st1]);
            st1++;
        }

        while(st2 < e2){
            merge.push_back(nums2[st2]);
            st2++;
        }
        int n = merge.size(); 

    if(n % 2 == 0){
        return (double)( merge[n/2 -1 ] + merge[n/2]) / 2;
    }
    else 
        return (double) merge[n/2];

    }
};