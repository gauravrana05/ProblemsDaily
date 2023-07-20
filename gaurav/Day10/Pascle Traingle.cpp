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

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector <int> > ans;
        
        rep(i, 0, numRows){
            vector<int> temp;
            rep(j, 0, i + 1){
            
            if( j == 0 || j == i ){
            temp.pb(1);
            }
            else{
                temp.pb(ans[i-1][j] + ans[i-1][j-1]);
            }
            }
            ans.pb(temp);
        }
        return ans;
    }
};