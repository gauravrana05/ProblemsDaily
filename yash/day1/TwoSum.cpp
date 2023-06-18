#include<iostream>
#include<vector>
using namespace std;

int main()
{
int a,target=9;
vector<int>nums{2,7,5,11};
vector<int>sol;
for(int i=0;i<nums.size()-1;i++){
	for(int j=i+1; j<nums.size(); j++ ){
		if(nums[i]+nums[j]==target){sol.push_back(i);sol.push_back(j);}
}


}
for (int i =0;i<2;i++){cout << sol[i];}

}
