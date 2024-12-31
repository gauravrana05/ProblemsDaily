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
class Solution {
public:


    void recDP(int n, map<int, int> &mp){
        if(mp[n] != -1)
            return;

        if(n % 2 == 0 ){
            recDP(n / 2, mp);
            mp[n] = mp[n / 2];
            }
        else{
            recDP(n-1, mp);
            mp[n] = mp[n - 1] + 1;}
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        map<int,int> dp;
        dp[0] = 0;
        for(int i = 1; i <=n; i++){
            dp[i] = -1;
            recDP(i, dp);
        }
        
        
        

        for(auto i : dp){
            ans.push_back(i.second);
        }
        return ans;


    }
};