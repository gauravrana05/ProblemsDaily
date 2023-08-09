#include<bits/stdc++.h>
using namespace std;
int main(){

	int arr[]={1,2,3,4,5,-1};
	int sum = 0, maxisum = arr[0];
	for(int i = 0;i<n;i++){

		sum+=arr[i];
		maxi = max(sum,maxi);
		if(sum<0){sum=0;}
	}
	return maxi;
}
