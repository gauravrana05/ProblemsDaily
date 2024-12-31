
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, d, h, o_h;
  double o_b, sum;
  cin >> t;
  while (t--)
  {
    cin >> n >> d >> h;
    vector<int> base(n);
    for (int &b : base)
      cin >> b;
    sort(base.begin(), base.end())
        sum = n * d * h / 2.0;
    if (n > 1)
      for (int i = 0; i < n - 1; i++)
        if (base[i + 1] - base[i] < h)
        {
          o_h = h - (base[i + 1] - base[i]);
          o_b = d / h * o_h;
          sum -= o_h * o_b / 2.0;
        }
    cout << sum << endl;
  }
}
