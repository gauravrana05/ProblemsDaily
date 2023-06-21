#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int absdiff(int a, int b){
int diff = a-b;
if (diff>0){return diff;}
else {return -1*diff;}
}

int main(){
vector<int> arr{4,0,5,-5,3,3,0,-4,-5};
int target=-2,mindiff=10000,ans,sum,diff;
int n = arr.size();
sort(arr.begin(),arr.end());
for(int i=0;i<n-2;i++){
	if(i>0 && arr[i-1]==arr[i]) {continue;}
	int j = i+1;
	int k = n-1;
	while(j<k){
		sum = arr[i]+arr[j]+arr[k];
                diff = absdiff(sum,target);
		if(sum>target)
			{j++;}
		else if(sum<target)
			{k--;}
		else{return target;}

		if(diff<mindiff)
			{mindiff = diff;ans=sum;}

		}
		}	
cout<< ans;
}
