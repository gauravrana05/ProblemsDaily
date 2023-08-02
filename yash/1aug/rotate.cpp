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
//Instead of breaking into two loops, we can use % for the indexes which are crossing n.for example, if we have to shift by 2 places, the n-1th index will go to n+1, and n+1%n will give 1, so it will cyclic rotate.
}
