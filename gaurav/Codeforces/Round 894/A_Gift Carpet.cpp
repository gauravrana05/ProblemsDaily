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
    int n, m;
    cin>>n>>m;

    vector<string> in;

    rep(i,0,n){
        string s;
        cin >> s;
        in.push_back(s);
    }
    // debug(m);
    vector<char> name;
    name.push_back('a');
    name.push_back('k');
    name.push_back('i');
    name.push_back('v');


    rep(i, 0, m){
        rep(j, 0, n){
            
            if(in[j][i] == name[name.size() - 1] ){
                name.pop_back();
                break;
            }
        }
    }
    if(name.size() == 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
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