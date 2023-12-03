#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, int itr, vector<int> output, vector<vector<int>>& ans){
	if(itr >= arr.size()){
		ans.push_back(output);
		return;
	}
//exclude
	solve(arr, itr+1, output, ans);
	output.push_back(arr[itr]);
	solve(arr, itr+1,output,ans);

}
int main(){
	int n;cin>>n;
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int temp = 0;	
		cin>>temp;
		arr.push_back(temp);

	}
	vector<int> output;
	vector<vector<int>> ans;
	int itr = 0;
	solve(arr,itr,output,ans);
	for(auto i: ans){
		for(auto j:i){cout<<j<<" ";}
		cout<<endl;
	}
}

