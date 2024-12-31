#include <bits/stdc++.h>
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void solve()
{

  int n, k, b;
  cin >> n >> k >> b;
  vector<int> entries(b);
  vector<int> signals(n + 1, 0);

  for (auto &i : entries)
  {
    cin >> i;
    signals[i] = 1;
  }
  int st = 2;
  int count = 0, minCount = k;
  for (int i = 1; i <= k; i++)
  {
    count += signals[i];
  }
  minCount = count;
  while (st + k - 1 <= n)
  {
    if (signals[st - 1] == 1)
    {
      count--;
    }
    if (signals[st + k - 1] == 1)
    {
      count++;
    }

    minCount = min(count, minCount);
    st++;
  }
  cout << minCount << endl;
}
int main()

{
  setIO("maxcross");
  solve();
  return 0;
}