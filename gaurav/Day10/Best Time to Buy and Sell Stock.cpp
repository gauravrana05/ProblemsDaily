#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <queue>
#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout << endl;
#define debug(x) cout << #x << " : " << x << endl;
#define debugg(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl;
#define debuggg(x, y, z) cout << #x << " : " << x << " " << #y << " : " << y << " " << #z << " : " << z << endl;

#define rep(i, s, e) for (bint i = s; i < e; i++)
#define repD(i, s, e) for (bint i = s - 1; i >= e; i--)

#define repS(i, s, e, step) for (bint i = s; i < e; i += step)
#define repDS(i, s, e, step) for (bint i = s - 1; i >= e; i -= step)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pr(x) cout << x << " "

#define prA(arr, s, e)               \
    {                                \
        for (bint i = s; i < e; i++) \
        {                            \
            cout << arr[i] << " ";   \
        }                            \
        cout << endl;                \
    }
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = prices[0];
        int mn = prices[0];
        int ans = 0;

        rep(i, 1, prices.size()){
            mx = max(mx, prices[i]); 
            ans = max(ans,mx - mn);

            if(mn > prices[i]){
                mx = prices[i];
                mn = prices[i];
            }
        }
        return ans;
        
    }
};