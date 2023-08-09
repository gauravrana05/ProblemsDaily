#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
        int jumps = 0;
        int currentPosition=0;
        int max=0;
        int maxIndex=0;
        
        while(currentPosition<n){
            if(currentPosition+arr[currentPosition]<n-1){
            for(int i=currentPosition+1;i<=currentPosition+arr[currentPosition];i++){
                int maxJump = i-currentPosition + arr[i];
                if(max<=maxJump){
                    max = maxJump;
                    maxIndex = i;
                }
            }
            currentPosition = maxIndex;
	cout<<currentPosition<<endl;
if(arr[currentPosition]==0){return -1;}
            jumps++;
        }
        else return ++jumps;
        }
    
return -1;

}

int main(){


int arr[] = {1,1,1,0,0};
int n = 5;
int answer = minJumps(arr,n);
cout<<answer<<endl;


}
