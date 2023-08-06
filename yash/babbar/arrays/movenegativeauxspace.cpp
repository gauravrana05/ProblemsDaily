#include<bits/stdc++.h>
using namespace std;
int main(){

	vector<int> arr = {1,-1,3,-2,-7,-5,11,6};
	int positive = 0;

	for(auto i:arr){
		if(i>=0){
			positive++;
		}
	}
	int positivepointer = 0;
	int ans[arr.size()]={0};
	for(int i = 0;i<arr.size();i++){
		if(arr[i]<0){ans[positive++]=arr[i];cout<<"Added negative number "<<arr[i]<<" at index" <<positive-1<<endl;}
		else if(arr[i]>0){ans[positivepointer++]=arr[i];cout<<"Added positive number "<<arr[i]<<" at index" <<positivepointer-1<<endl;}
	}

 


for(int j = 0; j<arr.size(); j++){cout<<ans[j]<<" ";}
}
