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


void solve () {
	int n;
    cin>>n;
    int p[n];
    rep(i, 0, n){
        cin>>p[i];
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        for (int  j = i; j < n; j++)
        {
            int sum = 0;
            for (int  l = i; l <= j; l++)
            {
                sum += p[l];
            }
            double avg = (double)sum / (j - i + 1); 
            // debugg(avg, i, j);
            for (int  l = i; l <= j; l++)
            {
                if(p[l] == avg){
                    ans++;
                    break;
                }
            }  
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}