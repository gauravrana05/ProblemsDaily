
#include <bits/stdc++.h>
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void solve()
{
  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> prefix(n + 1, 0);
    map<long long, long long> mp;
    mp[0]++;
    for (int i = 1; i <= n; i++)
    {
      prefix[i] = prefix[i - 1] + s[i - 1] - '0';
      mp[prefix[i] - i]++;
    }

    long long ans = 0;
    for (auto i : mp)
    {
      ans += (i.second * (i.second - 1)) / 2;
    }
    cout << ans << "\n";
  }
}
int main()

{
  solve();
  return 0;
}