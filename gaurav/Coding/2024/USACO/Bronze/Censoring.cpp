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

// void del(string &s, string t, int &i, int j){

//     while(j < t.size() && i < s.size() ){
//         // debugg(s[i], t[j]);
//         if(s[i] == t[j]){
//         i++;
//         j++;
//     }
//     else if(s[i] == t[0]){
//         del(s, t, i, 0);
//         i++;
//     }
//     else{
//         return;
//     }
// }
// // debug(i);
// string temp;
// rep(k, 0, i - t.size()){
//     temp = temp + s[k];
// }
// rep(k, i, s.size()){
//     temp = temp + s[k];
// }
// s= temp;
// i = i - t.size() - 1;
// // debugg(s, i);
// return;
// }

// void modify(string &s,string t, int i, int j){
//     if(i >= s.size())
//         return;

//     if(s[i] != t[j]){
//         modify(s, t, i + 1, j);
//     }
//     else{
//         // debugg(s[i], t[j]);
//         del(s, t, i, j);
//         modify(s, t, i + 1, j);
//     }
// }

void solve () {
	string s, t;
    cin>>s>>t;
    // modify(s, t, 0, 0);
    // cout<<s<<endl;

    string censored;
    rep(i, 0, s.size()){
        censored += s[i];

        if(censored.size()> t.size() && 
        censored.substr(censored.size() - t.size()) == t ){
            censored.resize(censored.size() - t.size());
        }
    }
    cout<<censored<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("censor");

    solve();
    return 0;
}