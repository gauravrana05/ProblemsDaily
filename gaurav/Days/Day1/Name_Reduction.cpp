#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout<<endl;
#define debug1(x) cout<<#x<<' '<<x<<endl;
#define debug2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repA(i,a,n) for(ll i=a;i<=n;i++)
#define repD(i,a,n) for(ll i=a;i>=n;i--)
#define repR(i,n) for(ll i=n-1;i>=0;i--)
#define rep1R(i,n) for(ll i=n;i>=0;i--)
#define repA1(i,a,n) for(ll i=a;i<n;i++)
#define repD1(i,a,n) for(ll i=a;i>n;i--)
#define repA2(i,a,n,step) for(ll i=a;i<n;i+=step)
#define repD2(i,a,n,step) for(ll i=a;i>n;i-=step)
#define repR2(i,n,step) for(ll i=n-1;i>=0;i-=step)
#define rep1R2(i,n,step) for(ll i=n;i>=0;i-=step)
#define repR2(i,n,step) for(ll i=n-1;i>=0;i-=step)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pr(x) cout<<x<<' '
#define prA(a,n) {for(ll i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;} 
#define pr1(a,n) {for(ll i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;}
 #define FORr(i, a, b) for (int i = b; i > a; i--)
#define eFORr(i, a, b) for (int i = b; i >= a; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define eFOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

void solve(){

int n;
string a,b;
cin>>a>>b;
int m;
cin>>m;
vector<string> c;
while(m--){
    string in;
    cin>>in;
    c.push_back(in);
}

int freq[26]={0};

for(int i = 0; i < a.length(); i++ ){
    freq[a[i] - 'a']++;
}

for(int i = 0; i < b.length(); i++ ){
    freq[b[i] - 'a']++;
}

// prA(freq,26);
for( int i = 0; i< c.size(); i++){

    for(int j = 0; j < c[i].length(); j++){
        if(freq[c[i][j] - 'a'] <=0){
            cout<<"NO";
            return;
        }
        else{
            freq[c[i][j] - 'a']--;
        }
    }
}

cout<<"YES";


}

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);

int t; cin>>t; 
while(t--){ solve(); cout<<endl;}

    return 0;
}


