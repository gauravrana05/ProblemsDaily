#include<iostream>
#include<vector>
using namespace std;
int main(){

	int arr1[5] = { 1,3,5,7,9 };
	int arr2[3] = {2,4,6};
	vector<int> arr3;
	int i=0,j=0;

	while( i<5 || j<3 ){
	if(i<5 && j<3){
		if(arr1[i]<arr2[j]){
			arr3.push_back(arr1[i]);
			i++;
		}
		else if (arr1[i]==arr2[j]){
			arr3.push_back(arr1[i]);
			arr3.push_back(arr2[j]);
		}
		else {
			arr3.push_back(arr2[j]);
			j++;

		}
	}
	else if(5>3){arr3.push_back(arr1[i]);i++;}
	else {arr3.push_back(j);j++;}

	}
for(int i:arr3){cout<<i<<" ";}
cout<<endl;

}
