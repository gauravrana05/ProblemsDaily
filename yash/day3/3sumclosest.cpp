#include<iostream>
#include<vector>

using namespace std;

int absdiff(int a, int b){
int diff = a-b;
if (diff>0){return diff;}
else {return -1*diff;}
}

int main(){
vector<int> arr{0,0,0};
int target=1,mindiff=10000,ans;
int n = arr.size();
for(int i=0;i<n;i++){
	if(i>0 && arr[i-1]==arr[i]) {continue;}
	int j = i+1;
	int k = n-1;
	int sum = arr[i]+arr[j]+arr[k];
	int diff = absdiff(sum,target);
	while(j<k){

		if(sum>target)
			{j++;}
		else if(sum<target)
			{k--;}
		else{return 0;}

		if(diff<mindiff)
			{mindiff = diff;ans=sum;}

		}
		}	
cout<< ans;
}
