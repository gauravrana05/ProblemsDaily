#include<iostream>
using namespace std;
int main(){

	int arr[7]={4,5,6,7,0,1,2};
	int target = 0;
	int st = 0, end = 6;
	int mid = (st+end)/2;
	while(st<=end){
		if(arr[mid]>=arr[0]){
			if(arr[0]<target && arr[mid]>target){
				end = mid;}
			else if(arr[mid]==target){cout<<mid;return mid;}
			else st = mid;
		}
		else{
			if(arr[mid]<target && arr[6]>target){st=mid;}
			else if (arr[mid]==target){cout<<mid;return mid;}
			else end = mid;
			

		}
		mid = (st+end)/2;

	}
cout <<-1;return -1;


}
