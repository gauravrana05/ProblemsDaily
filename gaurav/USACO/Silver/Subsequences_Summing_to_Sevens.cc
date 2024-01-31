
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

void solve()
{
  bint n;
  cin >> n;
  vector<bint> cows(n);
  for (auto &i : cows)
  {
    cin >> i;
  }
  vector<bint> prefix(n + 1, 0);
  for (bint q = 0; q <= n; q++)
  {
    prefix[q] = prefix[q - 1] + cows[q - 1];
  }

  bint sum = 0;
  bint mSum = 0;

  for (bint i = 0; i < n; i++)
  {
    for (bint j = i; j < n; j++)
    {
      sum = prefix[j + 1] - prefix[i];
      bint count = j - i + 1;
      if (sum % 7 == 0)
        mSum = max(count, mSum);
    }
  }
  cout << mSum << endl;
  ;
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("div7");

  solve();
  return 0;
}