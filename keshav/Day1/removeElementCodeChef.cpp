#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,k;
    cin>>n>>k;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"YES"<<endl;
        return ;
    }
    sort(a,a+n);
    a[0]+a[n-1]<=k ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}

int main() {
    int t;
    cin>> t;
    while(t--){
        solve();
    }
}
    