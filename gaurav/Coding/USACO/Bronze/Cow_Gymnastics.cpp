#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

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

#define rep(i, s, e) for (int i = s; i < e; i++)
#define repD(i, s, e) for (int i = s - 1; i >= e; i--)

#define repS(i, s, e, step) for (int i = s; i < e; i += step)
#define repDS(i, s, e, step) for (int i = s - 1; i >= e; i -= step)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pr(x) cout << x << " "

#define prA(arr, s, e)              \
    {                               \
        for (int i = s; i < e; i++) \
        {                           \
            cout << arr[i] << " ";  \
        }                           \
        cout << endl;               \
    }
using namespace std;
void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{

    int n, k;
    cin >> k >> n;
    int ranking[k][n + 1];
    rep(i, 0, k)
    {
        int t;
        rep(j, 0, n)
        {
            cin >> t;
            ranking[i][t-1] = j+1;
        }
    }
    int ans = 0;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
        bool flag = true;
            rep(h, 0, k)
            {   
                if (ranking[h][i] >= ranking[h][j]){
                    flag = false;
                }
            }
            if(flag)
                ans++;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("gymnastics");

    solve();
    return 0;
}