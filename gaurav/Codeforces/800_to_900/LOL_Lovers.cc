#include <bits/stdc++.h>
using namespace std;

void solve()
{

  int n;
  cin >> n;

  string s;
  cin >> s;

  if (s.size() == 1)
  {
    cout << -1 << endl;
    return;
  }

  int l = 0, o = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'L')
      l++;
    else
      o++;
  }
  int cl = 0, co = 0;

  for (int i = 0; i < s.size() - 1; i++)
  {
    if (s[i] == 'L')
      cl++;
    else
      co++;

    if (cl != l - cl && co != o - co)
    {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main()
{

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}