#include <bits/stdc++.h>
using namespace std;

array<int, 3> solve(vector<int> arr)
{
  array<int, 3> ans = {0, 0, 0};

  for (auto i : arr)
  {
    if (i > ans[0])
    {
      ans[2] = ans[1];
      ans[1] = ans[0];
      ans[0] = i;
    }
    else if (i > ans[1])
    {
      ans[2] = ans[1];
      ans[1] = i;
    }
    else if (i > ans[2])
    {
      ans[2] = i;
    }
  }
  return ans;
}

int main()
{
  vector<int> input = {1, 2, 3, 4, 5, 6, 7, 9, 8, 64, 32, 3, 1, 4, 5, 34, 4, 22};

  array<int, 3> threeLargest = solve(input);

  for (int i : threeLargest)
    cout << i << endl;
  return 0;
}