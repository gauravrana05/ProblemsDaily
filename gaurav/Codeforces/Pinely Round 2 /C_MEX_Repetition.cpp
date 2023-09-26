#include <iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
#define MOD 1000000007
#define inf 1e18
#define Fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define l(i, b) for (ll i = 0; i < b; i++)
#define lb(i, b) for (ll i = b - 1; i >= 0; i--)
#define lo(i, a, b) for (ll i = a; i < b; i++)
#define lob(i, a, b) for (ll i = a - 1; i >= b; i--)
#define vl vector<ll>
#define vi vector<int>
#define pq priority_queue
#define pb push_back
#define p push
#define F first
#define S second
#define N 1000001
#define read(a)     \
  for (auto &i : a) \
  cin >> i
#define print(a)   \
  for (auto i : a) \
  cout << i << " "
#define prec(a, x) cout << fixed << setprecision(x) << a << '\n';
#define all(x) (x).begin(), (x).end()
#define make_unique(vec) \
  sort(all(vec));        \
  vec.erase(unique(all(vec)), vec.end());
#define sort_by(cont, expr) sort(all(cont), [&](const auto &lhs, const auto &rhs) { return expr; })
#define endl '\n'
#define yes "YES" << endl;
#define no "NO" << endl;
using namespace std;
inline ll ceiling(ll a, ll b)
{
  return a % b == 0 ? a / b : (a / b) + 1;
}
inline ll gcd(ll a, ll b) { return __gcd(a, b); }
inline ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll power(ll a, ll n)
{
  if (n == 0)
    return 1;
  ll ans = power(a, n / 2);
  ans = (ans * ans) % MOD;
  if (n % 2)
    ans = (ans * a) % MOD;
  return ans % MOD;
}

vector<int> sieve()
{
  vector<bool> isPrime(N, 1);
  isPrime[0] = isPrime[1] = 0;
  for (int i = 0; i < N; i++)
  {
    if (!isPrime[i])
      continue;
    for (int j = 2 * i; j < N; j += i)
      isPrime[j] = 0;
  }
  vector<int> ans;
  for (int i = 0; i < isPrime.size(); i++)
  {
    if (isPrime[i])
      ans.push_back(i);
  }
  return ans;
}

//---------------------------------------------------------------------------------//

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n), ans(n);
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  int miss = (n * (n + 1)) / 2 - sum;
  k %= (n + 1);

  if (k == 0)
  {
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  if (k == 1)
  {
    cout << miss << " ";
    for (int i = 0; i < n - 1; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }
  ans[0] = a[n - k + 1];

  n++;
  a.push_back(miss);
  int j = (n - k + 1) % n;

  for (int i = 1; i < n - 1; i++)
  {
    ans[i] = a[j];
    j++;
    j %= n;
  }
  for (int i = 0; i < n - 1; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main()
{
  int testcase = 1;
  int t = 1;
  if (testcase)
  {
    cin >> t;
  }
  while (t--)
  {
    solve();
  }
}