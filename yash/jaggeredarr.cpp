#include<bits/stdc++.h>
using namespace std;
int main(){


	int** arr = new int*[5];
	int len[5]  = {1,2,3,2,1};
	for(int i=0;i<5;i++){
		arr[i] = new int[len[i]];
	}

	for(int i = 0;i<5;i++){
		for(int j=0;j<len[i];j++){
			cin>>arr[i][j];
		}
	}


	for(int i = 0;i<5;i++){
		for(int j=0;j<len[i];j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
		}




}
