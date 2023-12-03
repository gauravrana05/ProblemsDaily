#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[], int s, int e){
for(int i = 0; i<=e;i++){cout<<arr[i]<<" ";}cout<<endl;}
int merge(int arr[], int s, int mid, int e){
	int size1 = mid-s+1;
	int size2 = e-mid;
	int* a = new int[size1];
	int* b = new int[size2];
	for(int i = 0; i < size1; i++){
		a[i] = arr[s+i];
	}
	for(int j = 0; j<size2; j++){
		b[j] = arr[mid+j+1];
	}
	
	int x = 0; int y = 0, index = s, inversions = 0; 
	while(x<size1 && y<size2){
		if(a[x]<b[y]){
			arr[index++] = a[x++];
		}
		else if(a[x]>b[y]){
			arr[index++] = b[y++];
			inversions += size1-x;
		}
		else {
			arr[index++] = a[x++];y++;
		}

	}
	while(x<size1){arr[index++] = a[x++];}
	while(x<size2){arr[index++] = b[y++];}
//	printarray(arr,s,e);
	delete[] a;
	delete[] b;
	return inversions;
}
int mergeSort(int arr[],int s,int e){	
	int inversions=0;
	if(s<e){
		int mid = (s+e)/2;
		inversions += mergeSort(arr,s,mid);
		//cout<<"a: ";printarray(arr,s,mid);cout<<endl;
		inversions += mergeSort(arr,mid+1,e);
		//cout<<"b: ";printarray(arr,mid+1,e);cout<<endl;
		inversions += merge(arr,s,mid,e);
	}
	return inversions;
}



int main(){
	int n;cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++ ){
		cin>>arr[i];
	}
	cout<<"The number of inversions required are: "<<mergeSort(arr,0,n-1)<<endl;
}
