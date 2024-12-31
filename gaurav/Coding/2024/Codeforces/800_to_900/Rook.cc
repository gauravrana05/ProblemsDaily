#include <bits/stdc++.h>
using namespace std;

void solve()
{

  string s;
  cin >> s;
  char row = s[1];
  char col = s[0];

  for (int i = 0; i < 8; i++)
  {
    if (row - '0' - 1 != i)
      cout << col << i + 1 << endl;
  }
  for (int i = 0; i < 8; i++)
  {
    if (col - 'a' != i)
      cout << (char)('a' + i) << row << endl;
  }

  cout << endl;
}
int main()
{

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}