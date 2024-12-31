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

#define prA(arr, s, e)                                 \
  {                                                    \
    pr("Printing Array: ") for (int i = s; i < e; i++) \
    {                                                  \
      cout << arr[i] << " ";                           \
    }                                                  \
    cout << endl;                                      \
  }
using namespace std;
void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void shift(vector<int> &pos, int end, int val)
{
  for (int i = 0; i < end; i++)
  {
    pos[i] = pos[i + 1];
  }
  pos[end] = val;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> entries(n);
  for (auto &i : entries)
    cin >> i;

  if (entries[0] == -1)
    entries[0] = 0;

  int aMin = 1, aMax = 0;
  int log = 0;
  for (int i = 1; i < n; i++)
  {
    if (entries[i] == -1)
    {
      log++;
    }
    else
    {
      if (entries[i] > log + 1)
      {
        pr(-1);
        return;
      }
      else if (entries[i] == log + 1)
      {
        log++;
        continue;
      }
      else
      {
        log = entries[i];
        aMin++;
      }
    }
  }
  log = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (log == 0 && entries[i] == -1 || (entries[i] == 0))
    {
      log = 0;
      aMax++;
      continue;
    }
    else if (entries[i] != -1)
    {
      log = entries[i];
    }

    log--;
  }
  if (log)
  {
    pr(-1);
    return;
  }
  pr(aMin);
  pr(aMax);
  br;
}

int main()
{
  ios_base::sync_with_stdio(0);
  // setIO("taming");

  solve();
  return 0;
}