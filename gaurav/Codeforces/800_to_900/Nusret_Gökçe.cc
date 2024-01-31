#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, m;
  cin >> n >> m;
  vector<int> salt(n, 0);
  for (auto &i : salt)
    cin >> i;

  // vector<int> preSum(n + 1, 0);

  // for (int i = 1; i <= n; i++)
  // {
  // preSum[i] += salt[i - 1];
  // }

  vector<int> reqF(n, 0);
  vector<int> reqR(n, 0);

  for (int i = 0; i < n - 1; i++)
  {
    int dif;
    if (salt[i] < salt[i + 1])
    {

      dif = abs(salt[i] - salt[i + 1]);
      if (dif > m)
      {
        reqF[i] = dif - m;
        salt[i] += reqF[i];
      }
    }
    else if (i && salt[i] > salt[i + 1])
    {
      dif = abs(salt[i] - salt[i + 1]);
      if (dif > m)
      {
        reqF[i + 1] = dif - m;
        salt[i + 1] += reqF[i + 1];
      }
    }
  }

  for (int i = n - 1; i > 0; i--)
  {
    int dif;
    if (salt[i] < salt[i - 1])
    {

      dif = abs(salt[i] - salt[i - 1]);
      if (dif > m)
      {
        reqR[i] = dif - m;
        salt[i] += reqR[i];
      }
    }
    else if (salt[i] > salt[i - 1])
    {
      dif = abs(salt[i] - salt[i - 1]);
      if (dif > m)
      {
        reqR[i - 1] = dif - m;
        salt[i - 1] += reqR[i - 1];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << salt[i] << " ";
  }
  cout << endl;
  return 0;
}