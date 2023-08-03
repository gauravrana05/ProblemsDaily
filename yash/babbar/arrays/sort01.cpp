#include<bits/stdc++.h>
using namespace std;
void printarray(vector<int> v){
	for(auto i:v)
	{
		cout<<i<<" ";
	}
}

int main(){
	vector<int> arr = {0 ,2 ,1 ,2 ,0};
	int s = 0, e = arr.size()-1,i=1;
	while(i<=e && s<e){
		if(arr[i]==0){
			swap(arr[i],arr[s]);
			s++;if(arr[i]==1){i++;}
		}
		else if (arr[i]==2){
			swap(arr[i],arr[e]);
			e--;if(arr[i]==1){i++;}	
		}
		i++;
		cout<<"s: "<<s<<" e: "<<e<<" i: "<<i<<endl;
		printarray(arr);
		cout<<endl;
		
	}
	for(auto i:arr){cout<<i<<" ";}
}
