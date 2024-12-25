#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("rental.in", "r", stdin);
  int n, r, m;
  cin >> n >> m >> r;
  vector<int> cow_milk(n);
  for (auto &i : cow_milk)
  {
    cin >> i;
  }
  vector<pair<int, int>> stores(m);
  for (auto &i : stores)
  {
    cin >> i.second >> i.first;
  }
  vector<int> farmers(r);
  for (auto &i : farmers)
  {
    cin >> i;
  }
  sort(cow_milk.begin(), cow_milk.end(), greater<int>());
  sort(stores.begin(), stores.end(), greater<pair<int, int>>());
  sort(farmers.begin(), farmers.end(), greater<int>());

  int shot_at, farmer_at, store_at;
  long long int total_money;

  shot_at = 0;
  farmer_at = 0;
  store_at = 0;
  total_money = 0;

  while (shot_at < n)
  {
    int sold_money = 0;
    int amt = cow_milk[shot_at];
    int cur_shop = store_at;
    int last = 0;

    while (cur_shop < m)
    {
      int sold = min(amt, stores[cur_shop].second);
      sold_money += sold * stores[cur_shop].first;
      amt -= sold;

      if (amt == 0)
      {
        last = sold;
        break;
      }
      else
      {
        cur_shop++;
      }
    }
    if (sold_money > farmers[farmer_at] || farmer_at >= r)
    {
      total_money += sold_money;
      store_at = cur_shop;

      if (store_at < m)
      {
        stores[store_at].second -= last;
      }
      shot_at++;
    }
    else
    {
      total_money += farmers[farmer_at];
      farmer_at++;
      n--;
    }
  }

  freopen("rental.out", "w", stdout);
  cout << total_money << endl;
  return 0;
}