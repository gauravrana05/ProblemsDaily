#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, m, j;
  cin >> n >> m;
  multiset<int> s;
  
  while (n--)
  {
    cin >> j;
    s.insert(j);
  }
  while (m--)
  {
    cin >> j;
    auto i = s.upper_bound(j);
    if (i == s.begin())
    {
      cout << "-1/n";
    }
    else
    {
      cout << *(--i) << endl;
      s.erase(i);
    }
  }
}