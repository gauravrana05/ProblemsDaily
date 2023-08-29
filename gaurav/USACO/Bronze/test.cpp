
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
    int field[10000][10000];
    int x = 5000, y = 5000;
    rep(i, 0 , 10000)
        rep(j, 0, 10000)
            field[i][j] = -1;
    int n;
    cin>>n;
    int time = 0;
    cout<<n;
    char dir;
    int val;
    int ans = INT_MAX;
    // rep(i, 0, n){
    //     cin>>dir>>val;
    //     cout<<dir<<val;
    //     if(dir == 'N'){
    //         while(val--){
    //             if(field[x][y] == -1){
    //             field[x][y] = time;
    //             }
    //             else{
    //                 ans = min(ans, time - field[x][y]);
    //                 field[x][y]= time;
    //             }
    //             time++;
    //             x--;
    //         }
    //     }
    //     else 
    //     if(dir == 'W'){
    //         while(val--){
    //             if(field[x][y] == -1){
    //             field[x][y] = time;
    //             }
    //             else{
    //                 ans = min(ans, time - field[x][y]);
    //                 field[x][y]= time;
    //             }
    //             time++;
    //             y--;
    //         }
    //     }
    //     else 
    //     if(dir == 'E'){
    //         while(val--){
    //             if(field[x][y] == -1){
    //             field[x][y] = time;
    //             }
    //             else{
    //                 ans = min(ans, time - field[x][y]);
    //                 field[x][y]= time;
    //             }
    //             time++;
    //             y++;
    //         }
    //     }
    //     else 
    //     if(dir == 'S'){
    //         while(val--){
    //             if(field[x][y] == -1){
    //             field[x][y] = time;
    //             }
    //             else{
    //                 ans = min(ans, time - field[x][y]);
    //                 field[x][y]= time;
    //             }
    //             time++;
    //             x++;
    //         }
    
    //     }
    // }
    cout<<ans<<endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    setIO("lostcow");

    solve();
    return 0;
}