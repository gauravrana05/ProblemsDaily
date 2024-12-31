#include <bits/stdc++.h>
using namespace std;

class Edge
{

  int a, b, w;
  bool operator<(const Edge &y) { return w < y.w; }
  bool operator<(const Edge &y)
  {
    if (w != y.w)
    {
      return w < y.w;
    }
    return a < y.a;
  }
};

sort(begin(v), end(v), [](const Edge &x, const Edge &y)
     { return x.w < y.w; })