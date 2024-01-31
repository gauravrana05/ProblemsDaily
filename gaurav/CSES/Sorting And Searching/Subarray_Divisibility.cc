#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int n;
  cin >> n;

  vector<long long int> arr(n);
  for (auto &i : arr)
    cin >> i;

  vector<long long> prefix_sum(n);

  prefix_sum[0] = arr[0] % n;

  for (int i = 1; i < n; i++)
  {
    prefix_sum[i] = ((prefix_sum[i - 1] + arr[i]) % n + n) % n;
  }
  map<long long, long long> mp;

  mp[0] = 1;
  for (auto i : prefix_sum)
  {
    mp[i]++;
  }
  long long int ans = 0;
  for (auto i : mp)
  {
    ans += i.second * (i.second - 1) / 2;
  }
  cout << ans;
  cout << endl;
}
int main()
{

  solve();
  return 0;
}