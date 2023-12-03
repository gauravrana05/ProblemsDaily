#include <iostream>

using namespace std;

 

void merge(int arr[], int s, int mid, int e){

    int len1 = mid-s+1;

    int len2 = e-mid;

    int* left = new int[len1];

    int* right = new int[len2];

    for(int i = 0; i<len1;i++){

        left[i] = arr[s+i];

    }

    for(int j=0;j<len2;j++){

        right[j] = arr[mid+j+1];

    }

   

    int i1=0,i2=0,i3=s;

    while(i1<len1 && i2<len2){

        if(left[i1]<=right[i2]){

            arr[i3++] = left[i1++];

        }

        else {

            arr[i3++] = right[i2++];

        }

    }

    while(i1<len1){arr[i3++]=left[i1++];}

    while(i2<len2){arr[i3++]=right[i2++];}

 

    delete[] left;

    delete[] right;

   

}

 

 

void mergeSort(int arr[],int s,int e){

    if(s>=e){return;}

    int mid = (s+e)/2;

   

    mergeSort(arr, s, mid);

    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,e);

   

}

 

 

 

 

int main() {

int arr[10]={4,3,13,34,23,435,66,-1,33,34};

mergeSort(arr,0,9);

 

for(auto i:arr){cout<<i<<" ";}

 

    return 0;

}
