#include<iostream>
using namespace std;
bool binarySearch(int arr[],int size,int key){
int mid = size/2;
if(size<=1&&arr[mid]!=key){return false;}

if(key==arr[mid]){return true;}
else if(key<arr[mid]){return binarySearch(arr,size-mid,key);}
else return binarySearch(arr+mid,size-mid,key);

}

int main(){
	int arr[5] = {2,4,6,10,14};
	int size = 5;
	int key = 4;
	cout<<binarySearch(arr,size,key);
}
