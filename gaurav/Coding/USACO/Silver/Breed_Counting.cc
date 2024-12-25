#include <bits/stdc++.h>
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void solve()
{
  int n, queries;

  cin >> n >> queries;
  vector<vector<int>> breed(n + 1, vector<int>(3, 0));
  vector<int> breeds(n);
  for (auto &i : breeds)
  {
    cin >> i;
  }

  for (int q = 1; q <= n; q++)
  {

    breed[q][0] = breed[q - 1][0];
    breed[q][1] = breed[q - 1][1];
    breed[q][2] = breed[q - 1][2];
    breed[q][breeds[q - 1] - 1]++;
  }
  while (queries--)
  {
    int a, b;
    cin >> a >> b;
    cout << breed[b][0] - breed[a - 1][0] << ' ';
    cout << breed[b][1] - breed[a - 1][1] << ' ';
    cout << breed[b][2] - breed[a - 1][2] << '\n';
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  setIO("bcount");
  solve();
  return 0;
}
