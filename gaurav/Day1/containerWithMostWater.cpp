#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //two pointer apprach
        int area;
        int n = height.size();
        int st = 0;
        int end = n-1;
        
        area = end * min(height[st], height[end]); 
        
        while(st < end){
            
            int newArea = (end - st ) * (min(height[st], height[end]));
            if( newArea > area)
                area = newArea;
            
            if(height[st] < height[end])
                st++;
            else
                end--;
                
        }
        return area;
    }
};