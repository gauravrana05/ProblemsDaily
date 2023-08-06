#include<bits/stdc++.h>
using namespace std;
int main(){

	vector<int> arr = {1,-1,3,2,-7,-5,11,6};
	int negative = arr.size()-1;
	if(arr[negative]<0){negative--;}

	for(int i=arr.size()-1;i>0;i--){
		if(arr[i]<0){swap(arr[i],arr[negative]);negative--;}

	}

for(auto i:arr){cout<<i<<" ";}
cout<<endl;
}
