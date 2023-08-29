/*
ID: gauravrana05
TASK: lostcow 
LANG: C++
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

#define rep(i,s,e) for(int i = s; i < e; i++)
using namespace std;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


void solve () {
	int n;
    cin>> n;
    int r[n];
    
    rep(i, 0, n){
        cin>>r[i];
    }
    int ans = 1e9;
    
    rep(i, 0, n){
    
    int count = 0;
            int j = i;
            rep( k, 0, n){
                count += r[j % n] * k;
                j++;
            }
    ans = min(ans, count);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("cbarn");

    solve();
    return 0;
}