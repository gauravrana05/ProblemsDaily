//Review
//forgot the x = m and y= m condition

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
#define debugg(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define debuggg(x,y,z) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl;

#define rep(i,s,e) for(int i = s; i < e; i++)
#define repD(i,s,e) for(int i = s-1;i >= e; i--)

#define repS(i,s,e,step) for(int i = s;i < e;i+=step)
#define repDS(i,s,e,step) for(int i = s-1;i >= e;i-=step)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

#define pr(x) cout<<x<<" "

#define prA(arr, s, e) {for(int i = s;i < e; i++){ cout<<arr[i]<<" ";}cout<<endl;} 
using namespace std;
void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


void solve () {
	
    int x, y, m;
    cin>>x>>y>>m;
    int ans = 0, val;
    for (int i = 0; x * i <= m; i++)
    {
        val = x * i;
        // debug(val);
        while(val + y <= m){
            val += y;
        }
        // debug(val);
        ans = max(ans, val);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("pails");

    solve();
    return 0;
}