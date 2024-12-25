#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
void getLeft(vector<int> height, vector<int> &left){
    left[0] = height [0];
    for(int i = 1; i < height.size(); i++ ){
        left[i] = max(left[i-1], height[i]);
    }
 
}
void getRight(vector<int> height, vector<int> &right){
    int n = height.size();
    right[n-1] = height[n-1];

    for(int i = n-2; i >= 0; i--){
    right[i] = max(right[i+1], height[i]);
    }
}
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n,-1);
        vector<int> right(n,-1);

        getLeft(height, left);
        getRight(height, right);
        
    int totalVol = 0;

    for( int i = 0; i < height.size(); i++){
        totalVol += min(left[i], right[i]) - height[i];
    }
    return totalVol;
    }
};