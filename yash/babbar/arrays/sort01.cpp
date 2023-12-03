#include<bits/stdc++>
using namespace std;
void printarray(vector<int> v){
	for(auto i:v)
	{
		cout<<i<<" ";
	}
}

int main(){
	vector<int> arr = {0 ,1 ,2,0,1,2,0,1,2,0,1,2,0,1,2,0,2,1,2,1,0,1,0,2};
	int s = 0, e = arr.size()-1,i=0;
	while(s<=e&&i<=e){
		printarray(arr);
		cout<<"s: "<<s<<" e: "<<e<<" i: "<<i<<endl;
		if(arr[i]==0){swap(arr[i],arr[s]);i++;s++;}
		else if(arr[i]==2){swap(arr[i],arr[e]);e--;}
		else i++;
		

	}

printarray(arr);

}
