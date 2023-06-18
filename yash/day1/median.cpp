#include<iostream>
#include<vector>
using namespace std;

int main(){

vector<int> a{1,3,6,10};
vector<int> b{2,4,5,7};
vector<int> c;
int i=0,j=0,median;
while (i<a.size() && j<b.size())
{
if(a[i]>b[j]){c.push_back(b[j]);j++;}
else {c.push_back(a[i]);i++;}
}

if(i==a.size()){while(j<b.size()){c.push_back(b[j]);j++;}}
else if (j==b.size()){while(i<a.size()){c.push_back(a[i]);i++;}}

if(c.size()%2!=0){median = (c[(c.size()+1)/2])/2;}
else {median = (c[c.size()/2]+c[c.size()/2+1])/2;}
return median;
}

