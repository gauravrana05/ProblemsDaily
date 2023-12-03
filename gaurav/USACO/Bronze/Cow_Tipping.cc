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

#define prA(arr, s, e)          \
  {                             \
    for (int i = s; i < e; i++) \
    {                           \
      cout << arr[i] << " ";    \
    }                           \
    cout << endl;               \
  }
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void update(vector<vector<int>> &grid, int x, int y)
{
  for (int i = 0; i <= x; i++)
  {
    for (int j = 0; j <= y; j++)
    {
      if (grid[i][j] == 0)
        grid[i][j] = 1;
      else
        grid[i][j] = 0;
    }
  }
}
void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));

  for (auto &i : grid)
  {
    string s;
    cin >> s;
    int itr = 0;
    for (auto &j : i)
    {
      j = s[itr] - 48;
      itr++;
    }
  }

  int count = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (grid[i][j] == 1)
      {
        count++;
        update(grid, i, j);
      }
    }
  }
  pr(count);
  br;
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("cowtip");

  solve();
  return 0;
}