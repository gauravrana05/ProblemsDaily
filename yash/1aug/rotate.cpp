#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	int k,i;
	cin>>k;

	vector<int> ans;
	for(i=arr.size()-k; i<arr.size(); i++)
	{
		ans.push_back(arr[i]);	

	}

	for(i=0;i<arr.size()-k;i++)
	{ans.push_back(arr[i]);}
for(i=0;i<ans.size();i++){
	cout<<ans[i];

}

}
