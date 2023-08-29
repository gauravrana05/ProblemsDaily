#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#define rep(i, s, e) for (int i = s; i < e; i++)
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
    int ans[26], front[26], back[26];

    rep(i, 0, 26)
    {
        ans[i] = 0;
    }

    while (n--)
    {
        string f, b;
        cin >> f >> b;

        rep(i, 0, 26)
        {
            front[i] = 0;
            back[i] = 0;
        }

        rep(i, 0, f.size())
        {
            front[f[i] - 'a']++;
        }
        rep(i, 0, b.size())
        {
            back[b[i] - 'a']++;
        }

        rep(i, 0, 26)
        {
            ans[i] += max(back[i], front[i]);
        }
    }
    rep(i, 0, 26)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    setIO("blocks");

    solve();
    return 0;
}