#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long;
using ld = long double;

int N, ans = -1;
int outdeg[105], indeg[105];

void solve()
{
  cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    cin >> a >> b;
    outdeg[a]++;
    indeg[b]++;
  }
  for (int i = 1; i <= N; ++i)
  {
    if (outdeg[i] == 0 && ans != -1)
    {
      ans = -1;
      break;
    }
    if (outdeg[i] == 0)
      ans = i;
  }
  cout << ans;
}

void setIO(string name = "")
{
  cin.tie(0)->sync_with_stdio(0);
  if (name.length())
  {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout); 
  }
}

int main()
{
  setIO("factory");

  int t = 1;
  while (t--)
  {
    solve();
  }
  return 0;
}