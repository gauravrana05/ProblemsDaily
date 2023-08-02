#include<iostream>
using namespace std;
int main(){

//if an array is sorted and rotated, there will exist only one or less than one pair of continous numbers for which nums[i-1]>nums[i].

int count = 0;
n = nums.size();

for(int i=1;i<n;i++){
if(nums[n-1]>nums[i]){count++;}
}
if(nums[n-1]>nums[0]){count++;}

return count<=1;


}
