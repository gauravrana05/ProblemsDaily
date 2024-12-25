#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
int main()
{
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);

  int n, k;

  cin >> n >> k;

  while (n--)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = x1; i < x2; i++)
    {
      dp[i][y1]++;
      dp[i][y2]--;
    }
  }
  int ret = 0;
  for (int i = 0; i < 1001; i++)
  {
    for (int j = 0; j < 1001; j++)
    {
      if (dp[i][j] == k)
        ret++;
      dp[i][j + 1] += dp[i][j];
    }
  }
  cout << ret << endl;
  return 0;
}