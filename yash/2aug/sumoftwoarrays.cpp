#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int vectoint(vector<int> v){
	int sum = 0;
	for(int i=0;i<v.size();i++){sum=10*sum+v[i];}
	cout<<"sum: "<<sum<<endl;
	return sum;
}

vector<int> inttovector(int n){
	vector<int> ans;
	while(n!=0){ans.push_back(n%10);n/=10;}
	reverse(ans.begin(),ans.end());
	return ans;
}
void printvec(vector<int> v){
for(auto i:v){cout<<i<<" ";}
}

int main(){

	vector<int> v1 = {9,2,3,4};
	vector<int> v2 = {9,5,6,7};
	int answer = vectoint(v1) + vectoint(v2);
	vector<int> ans = inttovector(answer);
	printvec(ans);




}
