#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr{-2,-2,1,1,1,0,0,0,0,2,2,2,2,2};
	int uniq[2001]={0};
	int count[1001]={0};
	int coun=0;
	for(int i=0;i<14;i++){
		uniq[1000+arr[i]]++;

	}



	for(int i=0;i<2001;i++){
		if(uniq[i]!=0){
		coun = uniq[i];
		if(count[coun]!=0){cout<<'0';return 0;}
		count[coun]++;
		}

	}
	cout<<1;return 1;
}
