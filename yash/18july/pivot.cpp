#include<iostream>
using namespace std;
int main(){
	int arr[5]={8,10,7,1,3};
	int s=0,e=7;
	int mid = (s+e)/2;
	while(s<e){
		if(arr[mid]>=arr[0]){s=mid+1;}
		else e = mid;
		if(arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1]){cout<<"The pivot element is: "<<mid<<endl;return mid;}
		mid = (s+e)/2;	
	}



}
