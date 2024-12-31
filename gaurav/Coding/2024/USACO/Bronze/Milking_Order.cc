#include <bits/stdc++.h>

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

void solve()
{
  bint n, m, k;
  cin >> n >> m >> k;
  vector<int> order(m);
  for (auto &i : order)
    cin >> i;
  vector<pair<int, int>> fixed(k);
  for (auto &i : fixed)
    cin >> i.first >> i.second;

  int res = -1;
  for (int ii = 0; ii < n; ii++)
  {
    vector<int> placed(n + 1, -1);
    vector<int> mp(n, -1);

    int itr = 0;

    int blocked = ii + 1;
    mp[blocked - 1] = 1;
    placed[1] = blocked - 1;

    bool flag = false;

    for (auto i : fixed)
    {
      if (i.second == blocked)
      {
        flag = true;
        break;
      }
      mp[i.second - 1] = i.first;
      placed[i.first] = i.second - 1;
    }
    if (flag)
      continue;

    for (auto i : order)
    {
      if (placed[i] != -1)
      {
        itr = placed[i] + 1;
        continue;
      }

      while (mp[itr] != -1 && itr < n)
      {
        itr++;
      }

      if (itr >= n)
      {
        flag = true;
        break;
      }
      placed[i] = itr;
      mp[itr] = i;
      itr++;
    }
    if (flag)
      continue;

    for (int i = 1; i < m; i++)
    {
      if (placed[order[i - 1]] > placed[order[i]])
      {
        flag = true;
        break;
      }
    }
    if (flag)
      continue;

    cout << blocked << endl;
    return;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("milkorder");
  solve();
  return 0;
}