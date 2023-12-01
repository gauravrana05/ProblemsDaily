#include<iostream>
using namespace std;

int partition(arr,s,e){
	int count = 0;
	for(int i=0;i<e;i++){
		if(arr[i]<arr[0]){count++;}
		swap(arr[0],arr[count-1]);
		int i=0,j=e;
		while(s<=p && e >=p){
			if(arr[i]>arr[count-1]&& arr[j]<arr[count-1]){
			swap(arr[i++],arr[j--]);
			}
			else{
			i++;j--;
			}
		}

	}


}



void quickSort(int arr[],int s, int e){
	if(s>=e){return;}
	p=partition(arr,s,e);
	quickSort(arr, s, p);
	quickSort(arr,p+1,e);
}



int main(){
	int arr[5]={10,57,1,83,51};
	quickSort(arr,0,4);
	for(auto i:arr){cout<<i;}

}
