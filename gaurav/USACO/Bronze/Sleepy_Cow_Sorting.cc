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
  vector<int> pos(n);

  for (auto &i : pos)
  {
    cin >> i;
  }

  int ans = 0;
  for (;;)
  {
    int curr = pos[0];
    int temp = n - 1;
    // debugg(curr, temp);

    while (temp > 0)
    {
      // debugg(curr, pos[temp]);

      if (curr > pos[temp])
      {
        int val = pos[temp];
        pos[temp] = curr;
        shift(pos, temp - 1, val);
        // cout << "I am getting out here \n";
        break;
      }
      else if (curr < pos[temp] && pos[temp] > pos[temp - 1])
      {
        temp--;
        continue;
      }
      else
      {
        int val = pos[temp - 1];
        pos[temp - 1] = curr;
        shift(pos, temp - 2, val);
        // pr("get out \n");
        break;
      }
      temp--;
    }
    // debugg(temp, ans);
    if (temp == 0)
    {
      break;
    }
    else
    {
      ans++;
    }
  }
  pr(ans);
  br;
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("sleepy");

  solve();
  return 0;
}