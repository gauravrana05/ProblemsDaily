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

struct Point{
    int x, y;
};
int area(Point a, Point b, Point c){

    int length = max({abs(a.x - b.x), abs(a.x - c.x), abs(b.x - c.x)});
    int breadth = max({abs(a.y - b.y), abs(a.y - c.y), abs(b.y - c.y)});

    return abs(length * breadth);
}
void solve () {
    int n;
    cin>>n;
    vector<Point> p(n);

    rep(i, 0, n){
        cin>>p[i].x>>p[i].y;
    }

    int ans = 0;

    rep(i, 0, n - 2){
        
        rep(j, i + 1, n - 1){

            rep(k, j + 1, n){

                if(( p[i].x == p[j].x || p[i].x == p[k].x || p[k].x == p[j].x) &&
                   ( p[i].y == p[j].y || p[i].y == p[k].y || p[k].y == p[j].y)){
                    
                    ans = max(ans, area(p[i], p[j], p[k]));

                   }
            }
        }
    }

    cout<<ans<<endl;
	
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    setIO("triangles");

    solve();
    return 0;
}