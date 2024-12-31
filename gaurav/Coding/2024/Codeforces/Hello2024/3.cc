#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long t;
  cin >> t;

  while (t--)
  {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a)
      cin >> i;
    if (n == 1 || n == 2)
    {
      cout << 0 << endl;
      continue;
    }
    map<long long, priority_queue<long long>> mp;

    for (int i = 0; i < n; i++)
    {
      mp[a[i]].push(i);
    }

    vector<long long> temp = a;
    sort(temp.begin(), temp.end(), greater<int>());

    long long current = -1;
    for (int i = 0; i < n; i++)
    {
      if (current < mp[temp[i]].top())
      {
        current = mp[temp[i]].top();
        mp[temp[i]].pop();
      }
    }
    vector<long long> counter;

    for (int i = 0; i < n; i++)
    {
      if (mp.find(a[i]) != mp.end() && !mp[a[i]].empty())
      {
        counter.push_back(a[i]);
        mp[a[i]].pop();
      }
    }
    long long ans = 0;
    if (counter.size() == 0)
    {
      cout << ans << endl;
      ;
      continue;
    }
    for (int i = 0; i < counter.size() - 1; i++)
    {
      if (counter[i] < counter[i + 1])
      {
        ans++;
      }
    }
    cout << ans << endl;
  }
}