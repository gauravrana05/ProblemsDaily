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
    int n;
    cin >> n;

    vector<pair<int, pair<string, int>>> entries;
    rep(i, 0, n)
    {
        int day, reading;
        string cow, read;
        cin >> day >> cow >> read;

        if (read[0] == '-')
        {
            entries.pb({day, {cow, stoi(read)}});
        }
        else
        {
            entries.pb({day, {cow, stoi(read)}});
        }
    }
    sort(all(entries));

    int b = 7, e = 7, m = 7, ans = 0;
        string wall;
    for (auto i : entries)
    {
        string prev;

        if (i.second.first[0] == 'B')
            b += i.second.second;
        else if (i.second.first[0] == 'M')
            m += i.second.second;
        else
            e += i.second.second;

        int p_m = max({b, e, m});

        if(b == p_m)
            prev.pb('b');
        if(m == p_m)
            prev.pb('m');
        if(e == p_m)
            prev.pb('e');
        
        sort(all(prev));

        if(prev != wall){

            ans++;
            wall = prev;
        }
    }
    std::cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("measurement");

    solve();
    return 0;
}