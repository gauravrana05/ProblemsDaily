#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll ans = 0;
vector<pair<int, int>> cows;

ll search()
{
  sort(cows.begin(), cows.end());
  vector<pair<int, int>> pref(n), suf(n);

  auto upd = [](pair<int, int> a, int b) -> pair<int, int>
  {
    return {min(a.first, b), max(a.second, b)};
  };
  pref[0] = {cows[0].second, cows[0].second};
  for (int i = 1; i < n; ++i)
  {
    pref[i] = upd(pref[i - 1], cows[i].second);
  }
  suf[n - 1] = {cows[n - 1].second, cows[n - 1].second};
  for (int i = n - 2; i >= 0; i--)
  {
    suf[i] = upd(suf[i + 1], cows[i].second);
  }
  ll area = (ll)(cows.back().first - cows.front().first) * (pref.back().second - pref.back().first);
  ll best = LLONG_MAX;
  for (int i = 0; i < n - 1; i++)
  {
    if (cows[i].first != cows[i + 1].first)
    {
    }
  }
}