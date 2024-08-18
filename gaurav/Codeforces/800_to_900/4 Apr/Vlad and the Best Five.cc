#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve()
{
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (char c : s)
  {
    if (c == 'A')
    {
      a++;
    }
    else
    {
      b++;
    }
  }
  cout << (a > b ? 'A' : 'B') << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int i = 1; i <= tt; i++)
  {
    solve();
  }
  // solve();
}