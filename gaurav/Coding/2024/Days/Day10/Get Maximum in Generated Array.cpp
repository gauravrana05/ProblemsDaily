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
    int getMaximumGenerated(int n) {
        
        if(n < 2)
            return n;

        vector<int> arr(n + 1);
        
        arr[0] = 0;
        arr[1] = 1;
        int mx = -1;
        
        for(int i = 0 ; 2 * i + 1<= n; i++ ){
            arr[2 * i] = arr[i];
            arr[2 * i + 1] = arr[i] + arr[i + 1];
            if(mx < arr[2 * i] )
                mx = arr[2 * i];
            if(mx < arr[2 * i + 1] )
                mx = arr[2 * i + 1];
        }      
        
        return mx;
    }
};