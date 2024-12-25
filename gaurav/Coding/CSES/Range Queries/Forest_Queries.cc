#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, q;
  cin >> n >> q;
  vector<vector<int>> forest(n, vector<int>(n, 0));
  vector<vector<int>> preSum(n + 1, vector<int>(n + 1, 0));
  for (auto &i : forest)
  {
    for (auto &j : i)
    {
      char in;
      cin >> in;
      if (in == '*')
        j = 1;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {

      preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + forest[i - 1][j - 1];
    }
  }

  for (int i = 0; i < q; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long ans;
    ans = preSum[x2][y2] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1] + preSum[x1 - 1][y1 - 1];
    cout << ans << endl;
  }

  return 0;
}