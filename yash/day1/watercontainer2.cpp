//2 pointer approach as it will cover only the max area cases.


#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b){
if(a<b){return a;}
else return b;
}

int main()
{

vector<int> height{1,8,6,2,5,4,8,3,7};
int area, maxarea=0, start=0, last=height.size()-1;

while (start<last){
area = min(height[start] , height[last])*(last - start);
if(area>maxarea){maxarea = area;}

if(height[start] < height[last]){start++;}
else {last--;}


}
cout<<maxarea<<endl;
}
