 #include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout<<endl;
#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debugg(x,y) cout<<#x<<' : '<<x<<' '<<#y<<' : '<<y<<endl;
#define debuggg(x,y,z) cout<<#x<<' : '<<x<<' '<<#y<<' : '<<y<<' '<<#z<<' : '<<z<<endl;
#define rep(i,s,e) for(int i = s; i < e; i++)
#define repD(i,s,e) for(int i = s-1;i >= e; i--)
#define repS(i,s,e,step) for(int i = s;i < e;i+=step)
#define repDS(i,s,e,step) for(int i = s-1;i >= e;i-=step)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pr(x) cout<<x<<' '
#define prA(arr, s, e) {for(int i = s;i < e; i++){ cout<<arr[i]<<' ';}cout<<endl;} 
using namespace std;
void solve () {

    int x, y, n;
    cin>>x>>y>>n;

    vector<int> ans;
    int counter = 1;

    ans.push_back(y);

    repD(i, n - 1, 0){
        y = y - counter;
        // debug(x);
        ans.pb(y);
        counter++;
    }
    if(ans[ans.size() - 1] >= x ){
        // debug(ans[ans.size() - 1])
        // debug(x)
        ans.pop_back();
        ans.push_back(x);
        repD(i, n, 0){
            cout<<ans[i]<<" ";
        }
        br;
    }
    else{
        pr(-1);
        br;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--)
        solve();

    return 0;
}