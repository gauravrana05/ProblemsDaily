#include<iostream>
using namespace std;

void printarray(int arr[],int s,int e){
	for(int i=0;i<=e;i++){cout<<arr[i]<<" ";}
	cout<<endl;
}
// 10,57,1,83,51
int partition(int arr[],int s,int e){
	int count = s;
	for(int k=s+1;k<=e;k++){
		if(arr[k]<arr[s]){count++;}}
	swap(arr[s],arr[count]);
	int i=s,j=e;
	while(i<count && j>count){
		if(arr[i]>arr[count] && arr[j]<arr[count]){
			swap(arr[i++],arr[j--]);
		}
		else if(arr[i]>arr[count]){
			j--;
		}
		else if(arr[j]<arr[count]){i++;}
		else {i++;j--;}
	}
	printarray(arr,s,e);
	cout<<"Count is "<<count<<endl;
	return count;

}
void quickSort(int arr[],int s, int e){
	if(s>=e){return;}
	int p;
	p = partition(arr,s,e);
	quickSort(arr, s, p-1);
 	quickSort(arr,p+1,e);
}
int main(){
	int arr[6]={10,57,1,83,51,90};
	quickSort(arr,0,5);
	for(auto i:arr){cout<<i<<" ";}

}
