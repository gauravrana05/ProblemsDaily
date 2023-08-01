#include<iostream>
using namespace std;

bool isASolution(int n, int arr[], int m, int mid){
	int student=1,sum=0,sol;
	sol = mid;
	for(int i=0;i<n;i++){
		if( arr[i] + sum <= sol ){
			sum+=arr[i];
		}
		else {
			student++;

			if( student>m || arr[i]>sol){return false;}
			sum=arr[i]; 	
		}


	}


	return true;
}

int main(){


	int n = 4,arr[4]={10,20,30,40},m=2,solution=-1,sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int s=0;int e=sum;
	int mid = sum/m;

	while(s<e){
		cout<<"s: "<<s<<", e:"<<e<<", mid:"<<mid<<endl;
		if(isASolution(n,arr,m,mid))
		{solution = mid;e=mid;}
		else {s=mid+1;}
		mid = (e+s)/2;	
	}
	cout<<solution<<endl;

}
