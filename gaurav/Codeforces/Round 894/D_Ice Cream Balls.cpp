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


void solve(){
    bint n;
    cin>>n;

    bint st = 0, end = 2000000000;

    while(st < end){
        bint mid = ((end + st ) /2);

        
        if(mid * (mid - 1) / 2 > n ){
            end = mid - 1 ;
        }
        else if(mid * (mid - 1) / 2 == n){
            cout << mid + 1;
            return;
        }
        else{
            st = mid + 1;
        }
    }

    debugg(st, n);
    st--;
    cout<< st + ( n - (st * st - st) / 2);
    

}
int main(){
    
    int t;
    cin>> t;
    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}
