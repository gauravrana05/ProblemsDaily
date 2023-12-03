#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> arr = {1,2,3,4,5};
	int n = arr.size();
	vector<vector<int>> ans;
	for(int num = 0; num<(1<<n); num++){
		vector<int> out;
		for(int i = 0; i<arr.size();i++){
			if(num & (1<<i)){out.push_back(arr[i]);}
		}
		ans.push_back(out);
	}
for(auto i:ans){
	for(auto j:i){cout<<j<<" ";}

cout<<endl;
}

}
