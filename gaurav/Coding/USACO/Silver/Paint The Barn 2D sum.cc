
#include <bits/stdc++.h>

using namespace std;
#define LEN 11
int dp[LEN][LEN];
int main()
{
  // freopen("paintbarn.in", "r", stdin);
  // freopen("paintbarn.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  while (n--)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    dp[x1][y1]++;
    dp[x1][y2]--;
    dp[x2][y1]--;
    dp[x2][y2]++;
  }

  int ret = 0;
  for (int i = 1; i < LEN; i++)
  {
    for (int j = 1; j < LEN; j++)
    {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] += dp[i - 1][j];
      dp[i][j] -= dp[i - 1][j - 1];

      if (dp[i][j] == k)
        ret++;
    }
  }
  cout << ret << endl;
  return 0;
}