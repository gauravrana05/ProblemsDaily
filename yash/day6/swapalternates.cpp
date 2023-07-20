#include<iostream>
using namespace std;
int main(){

int arr[5]={1,2,3,4,5},n=5;
for(int i=0;i<=n-2;i+=2){

int temp = arr[i];
arr[i] = arr[i+1];
arr[i+1] = temp;
}

for(int i=0;i<n;i++){cout<<arr[i];}

}
