#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> arr = {1,2,3,4,5};

	int k,poin;
	cin>>k;
	int min = INT_MAX;
	for(int i = 1;i<=k;i++){
		min = INT_MAX;
		for(int j = 0; j<=arr.size()-1;j++){
			if(arr[j]<min){min = arr[j];poin=j;}

		}
		if(i==k){break;}
		else{
			arr[poin]=INT_MAX;
			

		}

	}
cout<<min<<endl;

}
