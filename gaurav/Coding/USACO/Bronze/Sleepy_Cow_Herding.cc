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

#define pr(x) cout << x << "\n"

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
  vector<int> pos(3);
  for (auto &i : pos)
    cin >> i;
  sort(all(pos));

  int d1 = pos[1] - pos[0];
  int d2 = pos[2] - pos[1];

  int low = min(d1, d2);
  int high = max(d1, d2);

  if (low == 1 && high == 1)
  {
    pr(0);
  }
  else if (low == 2 || high == 2)
  {
    pr(1);
  }
  else
  {
    pr(2);
  }
  pr(high - 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("herding");
  solve();
  return 0;
}