#include <bits/stdc++.h>
using namespace std;

int main()
{

  long long n;
  cin >> n;
  while (n--)
  {
    long long a, b;
    cin >> a >> b;
    ((a - b) % 2 == 0) ? cout << "Bob" : cout << "Alice";
    cout << endl;
  }
}