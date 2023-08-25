#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include <fstream>

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

const int MOD = 1e9 + 7;


int main() {
	ifstream fin("speeding.in");
	ofstream fout("speeding.out");

    int n, m;
    fin>>n>>m;
    vector<int> limit(100);
    int index = 0;
    rep(i, 0, n){
        int st = 0, end;
        int lim;
        fin>>end>>lim;
        while(st < end){
            limit[index] = lim;
            index++;
            st++;
        }
    }
    vector<int> cowS(100);
    index = 0;
    rep(i, 0, m){
        int st = 0, end;
        int lim;
        fin>>end>>lim;
        while(st < end){
            cowS[index] = lim;
            index++;
            st++;
        }
    }
    int ans = 0;
    rep(i, 0 , 100){
        ans = max(ans, cowS[i] - limit[i]);
    }
    fout<<ans<<endl;


    return 0;
}