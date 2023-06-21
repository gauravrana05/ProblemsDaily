#include<iostream>
#include<vector>
using namespace std;

int main(){

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> answer;
		vector<int> temp2{100,100,10,100};
	int n = nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<n-3;i++){
		if(i!=0 && nums[i-1]==nums[i]){continue;}
		for(int j=n-1;j>=i+3;j--){			
			if(j!=n-1 && nums[j+1]==nums[j]){continue;}
			int k = i+1;
			int l = j-1;
			long long sum = (long long)target-(long long)(nums[i]+nums[j]);
			while(k<l){
				long long s = nums[k]+nums[l];
				if(s<sum){k++;}
				else if(s>sum){l--;}
				else {
					vector<int> temp{nums[i],nums[k],nums[l],nums[j]};
					if(temp2 == temp){
						if(k==l) continue;
						else  {
							k++;
							l--;
							continue;
						}
					}
					temp2 = temp;
					answer.push_back(temp);
					k++;l--;
					// while(k<l && nums[k-1]==nums[k]){k++;}
					// 	while(k<l && nums[l+1]==nums[l]){j--;}
				}


			}



		}






	}
	return answer;
        
    }
};







}
