#include<bits/stdc++.h>
using namespace std;
int main(){

vector<int> nums = {1,2,3,4,5,6,100,7};

int min = INT_MAX;
int max = INT_MIN;

for(auto i:nums){
if(i<min){min = i;}
if(i>max){max = i;}
}

cout<<"min is --> "<<min<<endl;

cout<<"max is --> "<<max<<endl;

}
