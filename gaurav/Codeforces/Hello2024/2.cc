#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long cPlus = 0, cMinus = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '+')
        cPlus++;
      else
        cMinus++;
    }
    cout << abs(cPlus - cMinus) << endl;
  }
}