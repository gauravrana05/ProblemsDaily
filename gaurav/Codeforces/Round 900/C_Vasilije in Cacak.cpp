#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
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

#define rep(i,s,e) for(bint i = s; i < e; i++)
#define repD(i,s,e) for(bint i = s-1;i >= e; i--)

#define repS(i,s,e,step) for(bint i = s;i < e;i+=step)
#define repDS(i,s,e,step) for(bint i = s-1;i >= e;i-=step)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

#define pr(x) cout<<x<<" "

#define prA(arr, s, e) {for(bint i = s;i < e; i++){ cout<<arr[i]<<" ";}cout<<endl;} 

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        
        bint n,k,sum;
        cin>>n>>k>>sum;

        bint range_l, range_u;
        range_l = k * (k + 1) / 2;
        range_u = (n * (n + 1) / 2) - ((n - k) * (n - k + 1) / 2);
        
        if(sum >= range_l && sum <= range_u){
            pr("Yes");
        }
        else{
            pr("No");
        }
        br;
    }

    return 0;
}