#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b){
if(a>b){return b;}
else return a;
}

int main(){

vector<int> height{1,8,6,2,5,4,8,3,7};
int i=0,j=0,area,maxarea=0;

for(i=0;i<height.size()-1;i++){
for(j=i+1;j<height.size();j++){
area = (j-i)*min(height[i],height[j]);
if(area>maxarea){maxarea = area;}
}

}

cout<<maxarea;







}
