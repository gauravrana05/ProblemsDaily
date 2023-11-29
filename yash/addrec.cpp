#include<bits/stdc++.h>
using namespace std;

int addrecu(int arr[],int size){
	if(size==1){return arr[0];}
	return arr[0]+addrecu(arr+1,size-1);
	


}

int main(){

	int arr[6]={1,2,3,4,5,6};
	cout<<addrecu(arr,6)<<endl;
}



