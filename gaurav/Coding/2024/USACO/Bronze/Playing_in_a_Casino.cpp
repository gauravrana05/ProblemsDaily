

#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long int n,m;
    cin>>n>>m;
    vector<vector<long long int>> a(m, vector<long long int>(n,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[j][i];
        }
    }
    
    if(n==1){
        cout<<0<<endl;
        return ;
    }
    
    for(int i=0;i<m;i++){
        sort(a[i].begin(), a[i].end(), greater<long long int>());
    }
    
    long long int ans = 0;

    
    for(int i =0;i<m;i++){
        long long int count = a[i][0];
        for(int j=1;j<n;j++){
            ans+=(count - j*a[i][j]);
            count+=a[i][j];
        }
    }
    
    cout<<ans<<endl;
    
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}